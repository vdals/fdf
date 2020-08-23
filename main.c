/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnydia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 19:23:16 by jnydia            #+#    #+#             */
/*   Updated: 2020/06/13 19:23:19 by jnydia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_fdf *data)
{
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 53)
		exit(0);
	if (key == 24)
	{
		if (data->zoom < 500)
			data->zoom += 1;
	}
	if (key == 27)
	{
		if (data->zoom > 0)
			data->zoom -= 1;
	}
	deal_key2(key, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int		deal_key2(int key, t_fdf *data)
{
	if (key == 34)
	{
		if (data->isometr == 1)
			data->isometr = 0;
		else
			data->isometr = 1;
	}
	if (key == 6)
		data->shift_z += 1;
	if (key == 7)
		data->shift_z -= 1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc < 2)
		ft_putstr("usage: ./fdf <filename>");
	data = (t_fdf*)malloc(sizeof(t_fdf));
	ft_bzero(data, sizeof(t_fdf));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;
	data->isometr = 1;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}
