/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 14:10:46 by pchambon          #+#    #+#             */
/*   Updated: 2019/03/26 14:59:47 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				deal_arrow(int key, void *param)
{
	t_free		*free_list;

	free_list = (t_free *)param;
	if (key == 126)
		free_list->y -= 3;
	if (key == 125)
		free_list->y += 3;
	if (key == 123)
		free_list->x -= 3;
	if (key == 124)
		free_list->x += 3;
	if (free_list->i % 2 == 0)
		mlx_put_image_to_window(free_list->data->mlx_ptr,
			free_list->data->win_ptr, free_list->data->para_ptr,
				free_list->x, free_list->y);
	if (free_list->i % 2 != 0)
		mlx_put_image_to_window(free_list->data->mlx_ptr,
			free_list->data->win_ptr, free_list->data->iso_ptr,
				free_list->x, free_list->y);
	return (0);
}

void			deal_esc(t_free *free_list)
{
	free_all(free_list);
	exit(0);
}

void			deal_space(t_free *free_list, int i)
{
	if (i % 2 == 0)
		mlx_put_image_to_window(free_list->data->mlx_ptr,
			free_list->data->win_ptr, free_list->data->para_ptr,
				free_list->x, free_list->y);
	if (i % 2 != 0)
		mlx_put_image_to_window(free_list->data->mlx_ptr,
			free_list->data->win_ptr, free_list->data->iso_ptr,
				free_list->x, free_list->y);
}

int				deal_key(int key, void *param)
{
	static int	i = 0;
	t_free		*free_list;

	free_list = (t_free *)param;
	if (key == 53)
		deal_esc(free_list);
	if (key == 49)
		deal_space(free_list, ++i);
	free_list->i = i;
	if (key == 15)
	{
		free_list->x = 0;
		free_list->y = 0;
		deal_space(free_list, free_list->i);
	}
	if (key >= 123 && key <= 126)
		mlx_hook(free_list->data->win_ptr, 2, (1L << 0),
			deal_arrow, (void *)free_list);
	return (0);
}
