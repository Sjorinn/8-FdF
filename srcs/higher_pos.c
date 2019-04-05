/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   higher_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:33:05 by pchambon          #+#    #+#             */
/*   Updated: 2019/03/26 12:26:41 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			high_iy(t_point *head, int nb_points)
{
	int		i;
	int		nb;
	t_point *tmp;

	i = 0;
	tmp = head;
	nb = head->isoy;
	while (i < nb_points)
	{
		if (nb > tmp->isoy)
			nb = tmp->isoy;
		i++;
		tmp = tmp->next;
	}
	return (abs(nb));
}

int			high_ix(t_point *head, int nb_points)
{
	int		i;
	int		nb;
	t_point *tmp;

	i = 0;
	tmp = head;
	nb = head->isox;
	while (i < nb_points)
	{
		if (nb < tmp->isox)
			nb = tmp->isox;
		i++;
		tmp = tmp->next;
	}
	return (abs(nb));
}

int			high_py(t_point *head, int nb_points)
{
	int		i;
	int		nb;
	t_point *tmp;

	i = 0;
	tmp = head;
	nb = head->paray;
	while (i < nb_points)
	{
		if (nb < tmp->paray)
			nb = tmp->paray;
		i++;
		tmp = tmp->next;
	}
	return (abs(nb));
}

int			high_px(t_point *head, int nb_points)
{
	int		i;
	int		nb;
	t_point *tmp;

	i = 0;
	tmp = head;
	nb = head->parax;
	while (i < nb_points)
	{
		if (nb < tmp->parax)
			nb = tmp->parax;
		i++;
		tmp = tmp->next;
	}
	return (nb);
}
