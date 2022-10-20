/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monicaharutyunyan <monicaharutyunyan@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:32:37 by monicaharut       #+#    #+#             */
/*   Updated: 2022/10/20 10:36:49 by monicaharut      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	get_heigth(char *file_name)
{
	int		fd;
	int		
	char 	*line;

	fd = open(file_name, O_RDONLY, 0);
	
}

void	read_file(char *file_name, fdf *data)
{
	data->heigth = get_heigth(file_name);
}