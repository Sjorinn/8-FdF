/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:37:35 by pchambon          #+#    #+#             */
/*   Updated: 2019/03/16 14:40:33 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	dpoint(unsigned int *image, t_point *head)
{
	int		pos;
	t_point	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		pos = (((tmp->isoy) * WIDTH) + (tmp->isox));
		image[abs(pos)] = 0xFFFFFF;
		tmp = tmp->next;
	}
}

void	dseg_iso(t_point *coord, t_point *tmp, t_image *i)
{
	t_bres	seg;

	seg.x = coord->isox;
	seg.y = coord->isoy;
	seg.dx = abs(tmp->isox - seg.x);
	seg.dy = abs(tmp->isoy - seg.y);
	seg.err = (seg.dx > seg.dy ? seg.dx : -seg.dy) / 2;
	seg.sx = seg.x < tmp->isox ? 1 : -1;
	seg.sy = seg.y < tmp->isoy ? 1 : -1;
	while (!(seg.x == tmp->isox && seg.y == tmp->isoy))
	{
		if (is_in_range(seg.x, seg.y) == 1)
			i->tab[((seg.y * WIDTH) + seg.x)] = c_i(seg.y, coord, tmp);
		seg.e = seg.err;
		if (seg.e > -seg.dx)
		{
			seg.err -= seg.dy;
			seg.x += seg.sx;
		}
		if (seg.e < seg.dy)
		{
			seg.err += seg.dx;
			seg.y += seg.sy;
		}
	}
}

void	dseg_para(t_point *coord, t_point *tmp, t_image *image)
{
	t_bres	seg;

	seg.x = coord->parax;
	seg.y = coord->paray;
	seg.dx = abs(tmp->parax - seg.x);
	seg.dy = abs(tmp->paray - seg.y);
	seg.err = (seg.dx > seg.dy ? seg.dx : -seg.dy) / 2;
	seg.sx = seg.x < tmp->parax ? 1 : -1;
	seg.sy = seg.y < tmp->paray ? 1 : -1;
	while (!(seg.x == tmp->parax && seg.y == tmp->paray))
	{
		if (is_in_range(seg.x, seg.y) == 1)
			image->tab[((seg.y * WIDTH) + seg.x)] = c_p(seg.y, coord, tmp);
		seg.e = seg.err;
		if (seg.e > -seg.dx)
		{
			seg.err -= seg.dy;
			seg.x += seg.sx;
		}
		if (seg.e < seg.dy)
		{
			seg.err += seg.dx;
			seg.y += seg.sy;
		}
	}
}
