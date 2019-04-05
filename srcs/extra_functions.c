/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:43:37 by pchambon          #+#    #+#             */
/*   Updated: 2019/03/18 14:25:56 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		free_all(t_free *free_list)
{
	t_point *tmp;

	free(free_list->data);
	free_list->data = NULL;
	free(free_list->para);
	free_list->para = NULL;
	free(free_list->iso);
	free_list->iso = NULL;
	while (free_list->head)
	{
		tmp = free_list->head;
		free_list->head = free_list->head->next;
		free(tmp);
	}
	free_list->head = NULL;
	free_list = NULL;
}

int			count_pts(t_point *head)
{
	int		i;
	t_point	*tmp;

	i = 0;
	tmp = head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int			is_in_range(int x, int y)
{
	if (x - 1 < 0 || x + 1 > WIDTH || y - 1 < 0 || y + 1 > LONG)
		return (0);
	return (1);
}

void		reset_image(t_free *param)
{
	int i;

	i = 0;
	while (i < (WIDTH * LONG))
	{
		if (param->i % 2 != 0)
			param->iso->tab[i] = 0x000000;
		if (param->i / 2 != 0)
			param->para->tab[i] = 0x000000;
		i++;
	}
}
