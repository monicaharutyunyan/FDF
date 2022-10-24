/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharutyu <mharutyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:42:34 by monicaharut       #+#    #+#             */
/*   Updated: 2022/10/24 21:15:59 by mharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "fdf.h"
#include <stdio.h>

void	esc(t_fdf *data)
{
	int	i;

	i = 0;
	while(i < data->heigth)
	{
		free(data->z_matrix[i]);
		i++;
	}
	free(data->z_matrix[i]);
	exit(0);
}

int	deal_key(int key, t_fdf *data)
{
	ft_printf("%d\n", key);
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if(key == 53)
		esc(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

void	ft_clear(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			my_mlx_pixel_put(&data->image, j, i, 0x0000000);
			++j;
		}
		++i;
	}
}

int	ft_frame(t_fdf *data)
{
	ft_clear(data);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->image.img, 0, 0);
	mlx_do_sync(data->mlx_ptr);
	return (1);
}

int	main(int ac, char **av)
{
	t_fdf	*data;

	if (ac == 1 || ac > 2)
	{
		write(1, "ERROR!\n", 7);
		exit(0);
	}
	data = (t_fdf *)malloc(sizeof (t_fdf));
	read_file(av[1], data);
	data->zoom = 20;
	data->rot_angel = 0.8;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "FDF");
	data->image.img = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	data->image.addr = mlx_get_data_addr(data->image.img, &data->image.bbp,
			&data->image.line_len, &data->image.endian);
	mlx_loop_hook(data->mlx_ptr, ft_frame, data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}
