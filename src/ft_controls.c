/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <bstrong@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:21:42 by bstrong           #+#    #+#             */
/*   Updated: 2021/12/13 21:21:42 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_iso(t_fdf *fdf)
{
	fdf->alpha = -0.523599;
	fdf->betta = -0.523599;
	fdf->gamma = 0.523599;
}

static void	rotate_parall(t_fdf *fdf)
{
	fdf->alpha = 0;
	fdf->betta = 0;
	fdf->gamma = 0;
}

void	ft_move_zoom(int key, t_fdf *fdf)
{
	if (key == KEY_PLUS || key == SCROLL_UP)
		fdf->zoom++;
	if (key == KEY_MINUS || key == SCROLL_DOWN)
	{
		fdf->zoom--;
		if (fdf->zoom < 1)
			fdf->zoom = 1;
	}
	if (key == KEY_RIGHT)
		fdf->shift_x += 50;
	if (key == KEY_LEFT)
		fdf->shift_x -= 50;
	if (key == KEY_UP)
		fdf->shift_y -= 50;
	if (key == KEY_DOWN)
		fdf->shift_y += 50;
	draw_all(fdf, fdf->coords);
}

void	ft_rotate(int key, t_fdf *fdf)
{
	if (key == KEY_1)
		fdf->alpha += 0.05;
	if (key == KEY_2)
		fdf->alpha -= 0.05;
	if (key == KEY_3)
		fdf->betta -= 0.05;
	if (key == KEY_4)
		fdf->betta += 0.05;
	if (key == KEY_5)
		fdf->gamma += 0.05;
	if (key == KEY_6)
		fdf->gamma -= 0.05;
	if (key == KEY_ISO)
		rotate_iso(fdf);
	if (key == KEY_PAR)
		rotate_parall(fdf);
	draw_all(fdf, fdf->coords);
}
