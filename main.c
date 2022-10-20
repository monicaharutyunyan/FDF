/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monicaharutyunyan <monicaharutyunyan@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:42:34 by monicaharut       #+#    #+#             */
/*   Updated: 2022/10/20 10:32:26 by monicaharut      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "fdf.h"

int	main(int ac, char **av)
{
	fdf *data;

    data = (fdf*)malloc(sizeof(fdf));
    read_file(data);
}
