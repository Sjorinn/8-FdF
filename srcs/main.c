/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 09:03:01 by pchambon          #+#    #+#             */
/*   Updated: 2019/03/26 15:07:33 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			main_ext(t_mlx *data, t_image *iso, t_image *para, t_point *head)
{
	t_free	free_list;

	free_list.data = data;
	free_list.head = head;
	free_list.para = para;
	free_list.iso = iso;
	free_list.x = 0;
	free_list.y = 0;
	free_list.zoom_iso = 0;
	free_list.zoom_para = 0;
	data->kill = 0;
	data->iso_ptr = iso->ptr;
	data->para_ptr = para->ptr;
	coord(head, 0);
	bresenham_iso(head, iso);
	bresenham_para(head, para);
	ft_putstr("OK\n");
	mlx_key_hook(data->win_ptr, deal_key, &free_list);
	mlx_loop(data->mlx_ptr);
	return (0);
}

int			main(int argc, char **argv)
{
	t_mlx	*data;
	t_image	*iso;
	t_image	*para;
	t_point	*head;

	if (argc != 2)
		return (int_str("usage ./fdf test_map\n"));
	if (!(data = (t_mlx *)malloc(sizeof(t_mlx))))
		return (int_str("error_malloc\n"));
	if (!(iso = (t_image *)malloc(sizeof(t_image))))
		return (int_str("error_malloc\n") + int_free(data));
	if (!(para = (t_image *)malloc(sizeof(t_image))))
		return (int_str("error_malloc\n") + int_free(data) + int_free(iso));
	if ((head = parser(argc, argv)) == NULL)
		return (int_str("error\n") + int_free(data) + int_free(iso));
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, LONG, "FDF");
	iso->ptr = mlx_new_image(data->mlx_ptr, WIDTH, LONG);
	iso->tab = (unsigned int *)mlx_get_data_addr(iso->ptr, &(iso->bpp),
		&(iso->size), &(iso->endian));
	para->ptr = mlx_new_image(data->mlx_ptr, WIDTH, LONG);
	para->tab = (unsigned int *)mlx_get_data_addr(para->ptr, &(para->bpp),
		&(para->size), &(para->endian));
	main_ext(data, iso, para, head);
	return (0);
}
