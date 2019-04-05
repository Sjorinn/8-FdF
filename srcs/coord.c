/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:39:48 by pchambon          #+#    #+#             */
/*   Updated: 2019/03/26 13:21:12 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point		*coord_para(t_point *head, int coeff, int nb_pts)
{
	t_point	*tmp;
	int		center_x;
	int		center_y;

	tmp = head;
	while (tmp)
	{
		tmp->parax = (coeff * ((WIDTH - tmp->x) - tmp->z * -0.70710689672));
		tmp->paray = (coeff * ((LONG - tmp->y) - tmp->z * -0.70710666564));
		tmp = tmp->next;
	}
	center_x = (WIDTH - (high_px(head, nb_pts) - low_px(head, nb_pts))) / 2;
	center_y = (LONG - (high_py(head, nb_pts) - low_py(head, nb_pts))) / 2;
	tmp = head;
	while (tmp)
	{
		tmp->parax = center_x - (coeff *
			((-tmp->x) - tmp->z * -0.70710689672));
		tmp->paray = center_y - (coeff *
			((-tmp->y) - tmp->z * -0.70710666564));
		tmp = tmp->next;
	}
	return (head);
}

t_point		*coord_iso(t_point *head, int coeff, int nb_pts)
{
	t_point	*tmp;
	int		center_x;
	int		center_y;

	tmp = head;
	while (tmp != NULL)
	{
		tmp->isox = (coeff * ((tmp->x - tmp->y) * -0.86602529158));
		tmp->isoy = (coeff * (tmp->z + (tmp->x + tmp->y) * -0.50000019433));
		tmp = tmp->next;
	}
	center_x = (WIDTH - (high_ix(head, nb_pts) - low_ix(head, nb_pts))) / 2;
	center_y = (LONG - (high_iy(head, nb_pts) - low_iy(head, nb_pts))) / 2;
	tmp = head;
	while (tmp != NULL)
	{
		tmp->isox = center_x - (coeff *
			(-(tmp->x - tmp->y) * 0.86602529158));
		tmp->isoy = center_y - (coeff *
			(tmp->z + -(tmp->x + tmp->y) * 0.50000019433));
		tmp = tmp->next;
	}
	return (head);
}

t_point		*coord(t_point *head, int zoom)
{
	int		coeff;
	int		nb_pts;
	int		tmp;

	coeff = 1;
	nb_pts = count_pts(head);
	if (nb_pts == 1)
		exit(int_str("error\n"));
	tmp = nb_pts;
	while ((tmp *= 2) < WIDTH * LONG / 20)
		coeff += 2;
	if (zoom < coeff)
		coeff += zoom;
	coord_iso(head, coeff, nb_pts);
	coord_para(head, coeff, nb_pts);
	return (head);
}
