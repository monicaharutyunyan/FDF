/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharutyu <mharutyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:41:35 by mharutyu          #+#    #+#             */
/*   Updated: 2022/10/24 21:17:01 by mharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move(t_fdf *data, int key_code)
{
	if (key_code == K_W)
		data->shift_y -= 15;
	if (key_code == K_S)
		data->shift_y += 15;
	if (key_code == K_D)
		data->shift_x += 15;
	if (key_code == K_A)
		data->shift_x -= 15;
}

int	key_pressed(int key_code, t_fdf *data)
{
	if ((key_code == K_W) || (key_code == K_S) ||
		(key_code == K_D) || (key_code == K_A))
		ft_move(data, key_code);
	if (key_code == K_Z)
	{
		if (data->zoom >= 1900)
			return (0);
		else
			data->zoom += 1;
	}
	if (key_code == K_X)
	{
		if (data->zoom == 1)
			return (0);
		else
			data->zoom -= 1;
	}
	if (key_code == K_UP)
		data->rot_angel += 0.05;
	if (key_code == K_DOWN)
		data->rot_angel -= 0.5;
	return(0);
}
