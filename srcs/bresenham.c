/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 19:53:55 by pchambon          #+#    #+#             */
/*   Updated: 2019/03/16 13:45:36 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	bresenham_iso(t_point *head, t_image *image)
{
	t_point *tmp;
	t_point *tmp2;

	tmp = head;
	while (tmp)
	{
		tmp2 = head;
		while (tmp2)
		{
			if (tmp2->x == tmp->x - 1 && tmp2->y == tmp->y)
				dseg_iso(tmp, tmp2, image);
			tmp2 = tmp2->next;
		}
		tmp2 = head;
		while (tmp2)
		{
			if (tmp2->x == tmp->x && tmp2->y == tmp->y - 1)
				dseg_iso(tmp, tmp2, image);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	bresenham_para(t_point *head, t_image *image)
{
	t_point *tmp;
	t_point *tmp2;

	tmp = head;
	while (tmp)
	{
		tmp2 = head;
		while (tmp2)
		{
			if (tmp2->x == tmp->x - 1 && tmp2->y == tmp->y)
				dseg_para(tmp, tmp2, image);
			tmp2 = tmp2->next;
		}
		tmp2 = head;
		while (tmp2)
		{
			if (tmp2->x == tmp->x && tmp2->y == tmp->y - 1)
				dseg_para(tmp, tmp2, image);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
