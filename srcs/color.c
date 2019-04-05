/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 14:39:13 by pchambon          #+#    #+#             */
/*   Updated: 2019/03/17 16:19:27 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

unsigned long	creatergb(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void			get_color_ext(t_point *point)
{
	if (point->z >= 4 && point->z < 6)
	{
		point->color = BROWN;
		point->r = RBROWN;
		point->g = GBROWN;
		point->b = BBROWN;
	}
	if (point->z >= 6 && point->z < 8)
	{
		point->color = WHITE;
		point->r = RWHITE;
		point->g = GWHITE;
		point->b = BWHITE;
	}
}

void			get_color(t_point *point)
{
	if (point->z < 0)
	{
		point->color = WHITE;
		point->r = RWHITE;
		point->g = GWHITE;
		point->b = BWHITE;
	}
	if (point->z >= 0 && point->z < 2)
	{
		point->color = BLUE;
		point->r = RBLUE;
		point->g = GBLUE;
		point->b = BBLUE;
	}
	if (point->z >= 2 && point->z < 4)
	{
		point->color = GREEN;
		point->r = RGREEN;
		point->g = GGREEN;
		point->b = BGREEN;
	}
	get_color_ext(point);
}

int				c_i(int y, t_point *coord, t_point *tmp)
{
	double	r;
	double	g;
	double	b;
	double	percent;
	int		color;

	if (tmp->isoy != coord->isoy)
	{
		percent = fabs(((double)tmp->isoy - (double)y)) /
			fabs(((double)coord->isoy - (double)tmp->isoy));
		r = tmp->r + percent * (coord->r - tmp->r);
		g = tmp->g + percent * (coord->g - tmp->g);
		b = tmp->b + percent * (coord->b - tmp->b);
		color = (int)creatergb(r, g, b);
	}
	else
		return (coord->color);
	return (color);
}

int				c_p(int y, t_point *coord, t_point *tmp)
{
	double	r;
	double	g;
	double	b;
	double	percent;
	int		color;

	if (tmp->paray != coord->paray && coord->z != tmp->z)
	{
		percent = fabs(((double)tmp->paray - (double)y)) /
			fabs(((double)coord->paray - (double)tmp->paray));
		r = tmp->r + percent * (coord->r - tmp->r);
		g = tmp->g + percent * (coord->g - tmp->g);
		b = tmp->b + percent * (coord->b - tmp->b);
		color = (int)creatergb(r, g, b);
	}
	else
		return (coord->color);
	return (color);
}
