/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <bstrong@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 21:10:10 by bstrong           #+#    #+#             */
/*   Updated: 2021/12/21 21:56:17 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <limits.h>
# include <math.h>
# include "get_next_line.h"
# include <stdio.h>

# define MSG_NO_ARGS "Need more ARGS! -> ./fdf [PATH_MAP]\n"
# define MSG_ERROR_INIT "error init array-map\n"
# define MSG_ERROR_OPEN "error open file\n"
# define MSG_SUCC_EXIT "Exit?🤯\nOK, 🖐 GOOD BYE 🤪\n"
# define MSG_WINDOW_1 "Rotate OX: 1/2    Isometric: I     Zoom: +-"
# define MSG_WINDOW_2 "Rotate OY: 3/4    Parallel : P"
# define MSG_WINDOW_3 "Rotate OZ: 5/6    Move maps: <^v>"
# define W_WIN 1280
# define H_WIN 720
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_ESC 53
# define KEY_PLUS 24
# define KEY_MINUS 27
# define KEY_ISO 34
# define KEY_PAR 35
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 22
# define KEY_6 23

typedef struct s_list
{
	char			**line;
	ssize_t			len;
	struct s_list	*next;
}		t_list;

typedef struct s_img
{
	void	*addr;
	char	*data;
	int		lines;
	int		bpp;
	int		endian;
}		t_img;

typedef struct s_coords
{
	float	x;
	float	y;
	float	z;
	int		color;
}		t_coords;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	t_coords	**coords;
	t_img		img;
	ssize_t		height_map;
	ssize_t		width_map;
	float		zoom;
	float		alpha;
	float		betta;
	float		gamma;
	int			shift_x;
	int			shift_y;
	int			max_z;
	int			min_z;
}		t_fdf;

/*
**	reader_and_parser_utils
*/

void	ft_reader(t_fdf *fdf, char *file);
char	**ft_split(const char *s, char c, ssize_t *counter);
int		ft_atoi(const char *str);

/*
**	list_utils
*/

t_list	*ft_create_elem(char *data);
int		ft_list_push_back(t_list **begin, char *data);
int		ft_init_array(t_fdf *fdf, t_list *list);

/*
**	destroy_utils
*/

void	ft_destroy_fdf(t_fdf *fdf, t_list *list, char *str, int fd);
void	delete_list(t_list *list_temp);
void	ft_destroy_all(t_fdf *fdf, char *str);

/*
**	draw_utils
*/

void	draw_line(t_fdf *fdf, t_coords begin, t_coords end);
void	draw_all(t_fdf *fdf, t_coords **coords);
void	draw_background(t_fdf *fdf);

/*
**	controls_utils
*/

void	ft_move_zoom(int key, t_fdf *fdf);
void	ft_rotate(int key, t_fdf *fdf);

/*
**	rotate_utils
*/

void	rotate_x(t_fdf *fdf, t_coords *begin, t_coords *end);
void	rotate_y(t_fdf *fdf, t_coords *begin, t_coords *end);
void	rotate_z(t_fdf *fdf, t_coords *begin, t_coords *end);
void	ft_scale_move(t_fdf *fdf, t_coords *begin, t_coords *end);

/*
**	colors_utils
*/

void	set_color(t_fdf *fdf);
int		get_color_def(t_fdf *fdf, int current);
int		put_color(t_coords begin, t_coords end, t_coords cur, t_coords delta);

#endif