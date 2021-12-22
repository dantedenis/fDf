/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <bstrong@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:14:27 by bstrong           #+#    #+#             */
/*   Updated: 2021/12/22 19:54:09 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_reader(t_fdf *fdf, char *file)
{
	int		fd;
	char	*temp;
	t_list	*list_temp;

	fd = open(file, O_RDONLY);
	fdf->height_map = 0;
	list_temp = NULL;
	if (fd > 0 && fdf)
	{
		while (1)
		{
			temp = get_next_line(fd);
			if (!temp)
				break ;
			ft_list_push_back(&list_temp, temp);
			++(fdf->height_map);
		}
		if (ft_init_array(fdf, list_temp) < 0)
			ft_destroy_fdf(fdf, list_temp, MSG_ERROR_INIT, fd);
		delete_list(list_temp);
		close (fd);
		set_color(fdf);
	}
	else
		ft_destroy_fdf(fdf, NULL, MSG_ERROR_OPEN, 0);
}

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}
