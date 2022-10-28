/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharutyu <mharutyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:23:03 by mharutyu          #+#    #+#             */
/*   Updated: 2022/10/24 20:31:28 by mharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_steps(t_fdf *data, float *x_step, float *y_step, int *max)
{
	*x_step = data->cord.x1 - data->cord.x;
	*y_step = data->cord.y1 - data->cord.y;
	*max = max_f(mod_f(*x_step), mod_f(*y_step));
	*x_step /= *max;
	*y_step /= *max;
}
