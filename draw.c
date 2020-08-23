/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnydia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 19:22:53 by jnydia            #+#    #+#             */
/*   Updated: 2020/06/13 19:22:56 by jnydia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		isometric(float *x, float *y, int z)
{
	int		buff_x;
	int		buff_y;

	buff_x = *x;
	buff_y = *y;
	*x = (buff_x - buff_y) * cos(0.5);
	*y = (buff_x + buff_y) * sin(0.5) - z;
}

void		bonus_path(t_buff *b, t_fdf *data)
{
	b->x *= data->zoom;
	b->y *= data->zoom;
	b->x1 *= data->zoom;
	b->y1 *= data->zoom;
	b->z *= data->shift_z;
	b->z1 *= data->shift_z;
	if (b->z == 0 || b->z1 == 0)
		data->color = 0xffffff;
	if ((0 < b->z && b->z <= 10) || (0 < b->z1 && b->z1 <= 10))
		data->color = 0xe80c0c;
	if (b->z > 10 && b->z1 > 10)
		data->color = 0x0000ff;
	if (b->z < 0 && b->z1 < 0)
		data->color = 0x008000;
	if (data->isometr == 1)
	{
		isometric(&b->x, &b->y, b->z);
		isometric(&b->x1, &b->y1, b->z1);
	}
	b->x += data->shift_x;
	b->y += data->shift_y;
	b->x1 += data->shift_x;
	b->y1 += data->shift_y;
}

void		bresenham(float x1, float y1, t_fdf *data, t_buff *b)
{
	int		max;
	float	x_step;
	float	y_step;

	b->x1 = (float)x1;
	b->y1 = (float)y1;
	b->z = data->z_matrix[(int)b->y][(int)b->x];
	b->z1 = data->z_matrix[(int)b->y1][(int)b->x1];
	bonus_path(b, data);
	x_step = b->x1 - b->x;
	y_step = b->y1 - b->y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(b->x - b->x1) || (int)(b->y - b->y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, b->x, b->y, data->color);
		b->x += x_step;
		b->y += y_step;
	}
}

void		drawmap(int x, int y, t_fdf *data)
{
	t_buff	*b;

	b = (t_buff*)malloc(sizeof(t_buff));
	ft_bzero(b, sizeof(t_buff));
	if (x < data->width - 1)
	{
		b->x = (float)x;
		b->y = (float)y;
		bresenham(b->x + 1, b->y, data, b);
	}
	if (y < data->height - 1)
	{
		b->x = (float)x;
		b->y = (float)y;
		bresenham(b->x, b->y + 1, data, b);
	}
	free(b);
}

void		draw(t_fdf *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			drawmap(x, y, data);
			x++;
		}
		y++;
	}
}
