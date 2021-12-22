/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <bstrong@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:41:19 by bstrong           #+#    #+#             */
/*   Updated: 2021/12/14 21:41:19 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	delete_list(t_list *list_temp)
{
	t_list	*temp;
	int		i;

	while (list_temp)
	{
		temp = list_temp;
		list_temp = list_temp->next;
		i = 0;
		while (temp->line[i])
			free(temp->line[i++]);
		free(temp->line);
		free(temp);
	}
}

void	ft_destroy_fdf(t_fdf *fdf, t_list *list, char *str, int fd)
{
	int	i;

	delete_list(list);
	i = 0;
	while (fdf->coords && fdf->coords[i] && i < fdf->height_map)
		free(fdf->coords[i++]);
	free(fdf->coords);
	if (fd)
		close (fd);
	if (str)
		write(2, str, ft_strlen(str));
	free(fdf);
	exit(1);
}

void	ft_destroy_all(t_fdf *fdf, char *str)
{
	if (str)
		write(2, str, ft_strlen(str));
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_image (fdf->mlx, fdf->img.addr);
	ft_destroy_fdf(fdf, NULL, NULL, 0);
}
