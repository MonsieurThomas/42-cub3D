/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:05:53 by romainthoma       #+#    #+#             */
/*   Updated: 2023/04/21 16:41:04 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	get_textu_addr(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->texture[i].addr = mlx_get_data_addr(data->texture[i].img, \
		&data->texture[i].bits_per_pixel, &data->texture[i].line_length, \
		&data->texture[i].endian);
		i++;
	}
	if (data->texture[0].addr == NULL || \
	data->texture[1].addr == NULL || data->texture[2].addr == NULL
		|| data->texture[3].addr == NULL)
		return (ft_print_error("Error\nTexture problem29", NULL));//29
	return (0);
}

unsigned int	get_color_texture(t_data *data, int x, int y, int nb)
{
	char	*dst;

	dst = data->texture[nb].addr + (y * data->texture[nb].line_length \
	+ x * (data->texture[nb].bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
