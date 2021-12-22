/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <bstrong@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:42:48 by bstrong           #+#    #+#             */
/*   Updated: 2021/12/21 21:47:53 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_hook(int key, t_fdf *fdf)
{
	if (key == KEY_ESC)
		ft_destroy_all(fdf, MSG_SUCC_EXIT);
	if (key == KEY_MINUS || key == KEY_PLUS
		|| (key >= KEY_LEFT && key <= KEY_UP))
		ft_move_zoom(key, fdf);
	if ((key >= KEY_1 && key <= KEY_6) || key == KEY_ISO || key == KEY_PAR)
		ft_rotate(key, fdf);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc == 2 && argv[1])
	{
		fdf = (t_fdf *) malloc(sizeof(t_fdf));
		ft_reader(fdf, argv[1]);
		fdf->mlx = mlx_init();
		fdf->win = mlx_new_window(fdf->mlx, W_WIN, H_WIN, "Fil de Fer");
		fdf->img.addr = mlx_new_image(fdf->mlx, W_WIN, H_WIN);
		fdf->img.data = mlx_get_data_addr(fdf->img.addr, &fdf->img.bpp,
				&fdf->img.lines, &fdf->img.endian);
		draw_all(fdf, fdf->coords);
		mlx_hook(fdf->win, 2, 0, key_hook, fdf);
		mlx_loop(fdf->mlx);
	}
	else
		write(2, MSG_NO_ARGS, ft_strlen(MSG_NO_ARGS));
	return (0);
}
