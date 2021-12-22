/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <bstrong@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:30:17 by bstrong           #+#    #+#             */
/*   Updated: 2021/12/13 21:30:17 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(t_fdf *fdf, t_coords *begin, t_coords *end)
{
	float	pre_x;
	float	pre_y;

	pre_x = begin->x;
	pre_y = begin->y;
	begin->x = pre_x * cos(fdf->gamma) - pre_y * sin(fdf->gamma);
	begin->y = pre_x * sin(fdf->gamma) + pre_y * cos(fdf->gamma);
	pre_x = end->x;
	pre_y = end->y;
	end->x = pre_x * cos(fdf->gamma) - pre_y * sin(fdf->gamma);
	end->y = pre_x * sin(fdf->gamma) + pre_y * cos(fdf->gamma);
}

void	rotate_x(t_fdf *fdf, t_coords *begin, t_coords *end)
{
	float	pre_y;

	pre_y = begin->y;
	begin->y = pre_y * cos(fdf->alpha) + begin->z * sin(fdf->alpha);
	begin->z = -pre_y * sin(fdf->alpha) + begin->z * cos(fdf->alpha);
	pre_y = end->y;
	end->y = pre_y * cos(fdf->alpha) + end->z * sin(fdf->alpha);
	end->z = -pre_y * sin(fdf->alpha) + end->z * cos(fdf->alpha);
}

void	rotate_y(t_fdf *fdf, t_coords *begin, t_coords *end)
{
	float	pre_x;

	pre_x = begin->x;
	begin->x = pre_x * cos(fdf->betta) + begin->z * sin(fdf->betta);
	begin->z = -pre_x * sin(fdf->betta) + begin->z * cos(fdf->betta);
	pre_x = end->x;
	end->x = pre_x * cos(fdf->betta) + end->z * sin(fdf->betta);
	end->z = -pre_x * sin(fdf->betta) + end->z * cos(fdf->betta);
}

void	ft_scale_move(t_fdf *fdf, t_coords *begin, t_coords *end)
{
	begin->x *= fdf->zoom;
	begin->y *= fdf->zoom;
	begin->z *= fdf->zoom;
	end->x *= fdf->zoom;
	end->y *= fdf->zoom;
	end->z *= fdf->zoom;
	begin->x += fdf->shift_x + fdf->width_map / 2 + W_WIN / 2;
	begin->y += fdf->shift_y + fdf->height_map / 2 + H_WIN / 2;
	end->x += fdf->shift_x + fdf->width_map / 2 + W_WIN / 2;
	end->y += fdf->shift_y + fdf->height_map / 2 + H_WIN / 2;
}
