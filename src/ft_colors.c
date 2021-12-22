/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <bstrong@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:31:27 by bstrong           #+#    #+#             */
/*   Updated: 2021/12/21 21:31:27 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color(t_fdf *fdf)
{
	int	x;
	int	y;

	y = -1;
	while (++y < fdf->height_map)
	{
		x = -1;
		while (++x < fdf->width_map)
			fdf->coords[y][x].color = get_color_def(fdf, fdf->coords[y][x].z);
	}
}

int	get_color_def(t_fdf *fdf, int current)
{
	float	h;
	float	delta_z;

	delta_z = fdf->max_z - fdf->min_z;
	if (delta_z)
		h = (current - fdf->min_z) / delta_z;
	else
		h = 1;
	if (h < 0.1)
		return (0x5E3C65);
	if (h < 0.2)
		return (0x833F68);
	if (h < 0.4)
		return (0xF06E6C);
	if (h < 0.5)
		return (0xF7856C);
	if (h < 0.6)
		return (0xFD996B);
	if (h < 0.7)
		return (0xFFC568);
	if (h < 0.9)
		return (0xFFDE7A);
	return (0xFFDF8D);
}

int	put_color(t_coords begin, t_coords end, t_coords current, t_coords delta)
{
	int		rgb[3];
	float	pcent;
	int		b;
	int		e;

	b = begin.color;
	e = end.color;
	if (b == e)
		return (b);
	if (delta.x > delta.y)
		pcent = (current.x - begin.x) / (end.x - begin.x);
	else
		pcent = (current.y - begin.y) / (end.y - begin.y);
	rgb[0] = (b >> 16 & 0xff) + pcent * ((e >> 16 & 0xff) - (b >> 16 & 0xff));
	rgb[1] = (b >> 8 & 0xff) + pcent * ((e >> 8 & 0xff) - (b >> 8 & 0xff));
	rgb[2] = (b & 0xff) + pcent * (e & 0xff - b & 0xff);
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}
