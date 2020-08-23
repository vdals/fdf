/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnydia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 19:23:04 by jnydia            #+#    #+#             */
/*   Updated: 2020/06/13 19:23:07 by jnydia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>

# define MAX(a, b) (a > b ? a : b)
# define MOD(a) (a < 0 ? -a : a)

typedef struct	s_fdf
{
	int			width;
	int			height;
	int			**z_matrix;
	int			zoom;
	int			color;
	int			shift_x;
	int			shift_y;
	int			shift_z;
	int			isometr;

	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

typedef	struct	s_buff
{
	float		x;
	float		y;
	float		x1;
	float		y1;
	int			z;
	int			z1;
}				t_buff;

void			read_file(char *file_name, t_fdf *data);
void			fill_matrix(int *z_line, char *line);
int				get_width(char *file_name);
int				get_height(char *file_name);
void			bresenham(float x1, float y1, t_fdf *data, t_buff *b);
void			draw(t_fdf *data);
void			bonus_path(t_buff *b, t_fdf *data);
void			isometric(float *x, float *y, int z);
int				deal_key(int key, t_fdf *data);
void			drawmap(int x, int y, t_fdf *data);
int				deal_key2(int key, t_fdf *data);

#endif
