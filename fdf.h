/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharutyu <mharutyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:26:29 by monicaharut       #+#    #+#             */
/*   Updated: 2022/10/24 21:12:28 by mharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# define K_ESC 53
# define K_W 13
# define K_S 1
# define K_A 0
# define K_D 2
# define K_Z 6
# define K_X 7
# define K_UP 126
# define K_DOWN 125
# define K_RIGHT 124
# define K_LEFT 123
# define WIN_H 1080
# define WIN_W 1920

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bbp;
	int			line_len;
	int			endian;
}t_img;

typedef struct s_cord
{
	float	x;
	float	y;
	float	x1;
	float	y1;
}t_cord;

typedef struct s_fdf
{
	t_img	image;
	t_cord	cord;
	int		width;
	int		heigth;
	int		color;
	int		zoom;
	int		shift_x;
	int		shift_y;
	int		**z_matrix;
	float	rot_angel;
	void	*mlx_ptr;
	void	*win_ptr;
}t_fdf;

char	*get_next_line(int fd);
int		deal_key(int key, t_fdf *data);
int		color_f(int z, int z1);
float	max_f(float x, float y);
float	mod_f(float x);
void	draw(t_fdf *data);
void	bresenham(t_fdf *data);
void	isometric(float *x, float *y, int z, t_fdf *data);
void	read_file(char *file_name, t_fdf *data);
void	ft_zoomik_and_others(t_fdf *data, int *z, int *z1);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	ft_steps(t_fdf *data, float *step_x, float *step_y, int *max);

#endif
