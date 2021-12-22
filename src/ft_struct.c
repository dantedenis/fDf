/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <bstrong@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:46:42 by bstrong           #+#    #+#             */
/*   Updated: 2021/12/14 21:46:42 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*ft_create_elem(char *data)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->line = ft_split(data, ' ', &(new->len));
	new->next = NULL;
	return (new);
}

int	ft_list_push_back(t_list **begin, char *data)
{
	t_list	*add;

	add = *begin;
	if (add)
	{
		while (add->next)
			add = add->next;
		add->next = ft_create_elem(data);
	}
	else
		*begin = ft_create_elem(data);
	free(data);
	if (!add)
		return (-1);
	return (1);
}

static void	ft_correct_location(t_fdf *fdf)
{
	float	max_win;
	float	max_array;

	max_win = fmax(H_WIN, W_WIN);
	max_array = fmax(fdf->width_map, fdf->height_map);
	fdf->zoom = fmax(max_win, max_array) / fmin(max_win, max_array) / 2;
	fdf->max_z = INT_MIN;
	fdf->min_z = INT_MAX;
}

static void	ft_max_min_z(t_fdf *fdf, int z)
{
	if (z > fdf->max_z)
		fdf->max_z = z;
	if (z < fdf->min_z)
		fdf->min_z = z;
}

int	ft_init_array(t_fdf *fdf, t_list *list)
{
	int		i;
	int		j;

	i = -1;
	fdf->coords = (t_coords **) malloc(sizeof(t_coords *) * fdf->height_map);
	fdf->width_map = list->len;
	ft_correct_location(fdf);
	while (list && fdf->coords && ++i < fdf->height_map)
	{
		fdf->coords[i] = (t_coords *) malloc(sizeof(t_coords) * list->len);
		j = -1;
		if (!fdf->coords[i])
			return (-1);
		while (++j < list->len)
		{
			fdf->coords[i][j].z = ft_atoi(list->line[j]);
			fdf->coords[i][j].x = j - (fdf->width_map >> 1);
			fdf->coords[i][j].y = i - (fdf->height_map >> 1);
			ft_max_min_z(fdf, fdf->coords[i][j].z);
		}
		list = list->next;
	}
	return (i);
}
