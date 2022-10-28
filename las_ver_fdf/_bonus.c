/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharutyu <mharutyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:41:35 by mharutyu          #+#    #+#             */
/*   Updated: 2022/10/26 17:45:58 by mharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_pressed_bonus(int key_code, t_fdf *data)
{
	if ((key_code == K_W) || (key_code == K_S)
		|| (key_code == K_D) || (key_code == K_A))
		ft_move(data, key_code);
	if (key_code == K_ESC)
		esc(data);
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
		data->rot_angle += 0.05;
	if (key_code == K_DOWN)
		data->rot_angle -= 0.5;
	return (0);
}
