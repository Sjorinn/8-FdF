/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:01:11 by pchambon          #+#    #+#             */
/*   Updated: 2019/03/26 12:27:05 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			low_iy(t_point *head, int nb_points)
{
	int		i;
	int		nb;
	t_point *tmp;

	i = 0;
	tmp = head;
	nb = head->isoy;
	while (i < nb_points)
	{
		if (nb < tmp->isoy)
			nb = tmp->isoy;
		i++;
		tmp = tmp->next;
	}
	return (abs(nb));
}

int			low_ix(t_point *head, int nb_points)
{
	int		i;
	int		nb;
	t_point *tmp;

	i = 0;
	tmp = head;
	nb = head->isox;
	while (i < nb_points)
	{
		if (nb > tmp->isox)
			nb = tmp->isox;
		i++;
		tmp = tmp->next;
	}
	return (abs(nb));
}

int			low_py(t_point *head, int nb_points)
{
	int		i;
	int		nb;
	t_point *tmp;

	i = 0;
	tmp = head;
	nb = head->paray;
	while (i < nb_points)
	{
		if (nb > tmp->paray)
			nb = tmp->paray;
		i++;
		tmp = tmp->next;
	}
	return (abs(nb));
}

int			low_px(t_point *head, int nb_points)
{
	int		i;
	int		nb;
	t_point *tmp;

	i = 0;
	tmp = head;
	nb = head->parax;
	while (i < nb_points)
	{
		if (nb > tmp->parax)
			nb = tmp->parax;
		i++;
		tmp = tmp->next;
	}
	return (nb);
}
