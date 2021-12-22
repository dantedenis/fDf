/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <bstrong@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 21:06:31 by bstrong           #+#    #+#             */
/*   Updated: 2021/12/22 21:10:15 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_press(int key, int x, int y, void *p)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)p;
	if (key == SCROLL_UP || key == SCROLL_DOWN)
		ft_move_zoom(key, fdf);
	else if (key == 1)
		fdf->mouse.is_pressed = 1;
	return (0);
}

int	mouse_release(int key, int x, int y, void *p)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	(void)key;
	fdf = (t_fdf *)p;
	fdf->mouse.is_pressed = 0;
	return (0);
}

int	mouse_move(int x, int y, void *p)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)p;
	fdf->mouse.pre_x = fdf->mouse.x;
	fdf->mouse.pre_y = fdf->mouse.y;
	fdf->mouse.x = x;
	fdf->mouse.y = y;
	if (fdf->mouse.is_pressed)
	{
		fdf->betta += (x - fdf->mouse.pre_x) * 0.005;
		fdf->alpha += (y - fdf->mouse.pre_y) * 0.005;
		draw_all(fdf, fdf->coords);
	}
	return (0);
}
