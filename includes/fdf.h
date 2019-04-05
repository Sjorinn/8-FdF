/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:55:06 by pchambon          #+#    #+#             */
/*   Updated: 2019/04/04 12:08:34 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define LONG 1400
# define WIDTH 2560

# define BLUE 0x6464FF
# define WHITE 0xFFFFFF
# define BROWN 0x5F2B17
# define GREEN 0x259000
# define RBLUE 100
# define GBLUE 100
# define BBLUE 255
# define RWHITE 255
# define GWHITE 255
# define BWHITE 255
# define RBROWN 95
# define GBROWN 43
# define BBROWN 23
# define RGREEN 37
# define GGREEN 144
# define BGREEN 0

# include "../X-Libft/includes/libft.h"
# include "../MiniLibX/mlx.h"
# include <sys/types.h>
# include <math.h>

typedef	struct	s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				len;
	int				lar;
}				t_mlx;

typedef	struct	s_parser
{
	int				fd;
	int				len;
	int				tmp_len;
	char			*tmp;
	char			*line;
	char			*stock;
}				t_parser;

typedef	struct	s_point
{
	int				x;
	int				y;
	int				z;
	int				len;
	int				isox;
	int				isoy;
	int				parax;
	int				paray;
	int				color;
	int				r;
	int				g;
	int				b;
	struct s_point	*next;
}				t_point;

typedef struct	s_image
{
	void			*ptr;
	unsigned int	*tab;
	int				bpp;
	int				size;
	int				color;
	int				endian;
}				t_image;

typedef struct	s_bres
{
	int		sx;
	int		sy;
	int		err;
	int		e;
	int		x;
	int		y;
	int		dx;
	int		dy;
}				t_bres;

typedef struct	s_free
{
	struct s_mlx	*data;
	struct s_point	*head;
	struct s_image	*iso;
	struct s_image	*para;
	int				i;
	int				x;
	int				y;
	int				zoom_para;
	int				zoom_iso;
}				t_free;

int				count_pts(t_point *head);
int				is_in_range(int x, int y);
void			get_color(t_point *point);
void			reset_image(t_free *param);
void			free_all(t_free *free_list);
t_point			*parser(int argc, char **argv);
int				deal_key(int key, void *param);
t_point			*coord(t_point *head, int zoom);
int				low_ix(t_point *head, int nb_points);
int				low_iy(t_point *head, int nb_points);
int				c_i(int y, t_point *coord, t_point *tmp);
int				c_p(int y, t_point *coord, t_point *tmp);
int				low_py(t_point *head, int nb_points);
int				low_px(t_point *head, int nb_points);
int				high_iy(t_point *head, int nb_points);
int				high_ix(t_point *head, int nb_points);
int				high_px(t_point *head, int nb_points);
int				high_py(t_point *head, int nb_points);
void			dpoint(unsigned int *image, t_point *head);
void			bresenham_iso(t_point *head, t_image *image);
void			bresenham_para(t_point *head, t_image *image);
void			dseg_iso(t_point *coord, t_point *tmp, t_image *image);
void			dseg_para(t_point *coord, t_point *tmp, t_image *image);

#endif
