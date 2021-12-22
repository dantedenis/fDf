/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <bstrong@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:27:31 by bstrong           #+#    #+#             */
/*   Updated: 2021/12/21 21:55:22 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_info(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 50, H_WIN - 50, 0x4bf278, MSG_WINDOW_1);
	mlx_string_put(fdf->mlx, fdf->win, 50, H_WIN - 35, 0x4bf278, MSG_WINDOW_2);
	mlx_string_put(fdf->mlx, fdf->win, 50, H_WIN - 20, 0x4bf278, MSG_WINDOW_3);
}

static void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < W_WIN && y >= 0 && y < H_WIN)
	{
		i = (x * fdf->img.bpp >> 3) + (y * fdf->img.lines);
		fdf->img.data[i] = color;
		fdf->img.data[++i] = color >> 8;
		fdf->img.data[++i] = color >> 16;
	}
}

void	draw_background(t_fdf *fdf)
{
	int	*image;
	int	i;

	image = (int *)(fdf->img.data);
	i = -1;
	while (i++ < H_WIN * W_WIN)
	{
		if (i < W_WIN * (H_WIN - 70))
			image[i] = 0x041924;
		else
			image[i] = 0x30393d;
	}
}

void	draw_line(t_fdf *fdf, t_coords begin, t_coords end)
{
	int			pixels;
	t_coords	temp;
	t_coords	delta;

	rotate_x(fdf, &begin, &end);
	rotate_y(fdf, &begin, &end);
	rotate_z(fdf, &begin, &end);
	ft_scale_move(fdf, &begin, &end);
	delta.x = end.x - begin.x;
	delta.y = end.y - begin.y;
	pixels = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	delta.x /= pixels;
	delta.y /= pixels;
	temp.x = begin.x;
	temp.y = begin.y;
	while (pixels--)
	{
		put_pixel(fdf, temp.x, temp.y, put_color(begin, end, temp, delta));
		temp.x += delta.x;
		temp.y += delta.y;
	}
}

void	draw_all(t_fdf *fdf, t_coords **crd)
{
	int	x;
	int	y;

	draw_background(fdf);
	y = -1;
	while (++y < fdf->height_map)
	{
		x = -1;
		while (++x < fdf->width_map)
		{
			if (x != fdf->width_map - 1)
				draw_line(fdf, crd[y][x], crd[y][x + 1]);
			if (y != fdf->height_map - 1)
				draw_line(fdf, crd[y][x], crd[y + 1][x]);
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.addr, 0, 0);
	print_info(fdf);
}
