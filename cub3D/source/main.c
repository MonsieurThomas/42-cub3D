/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:10:16 by rthomas           #+#    #+#             */
/*   Updated: 2023/04/19 16:52:02 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	loop_create_wall(t_data *data)
{
	raycasting(data);
	mouvement(data);
	show_minimap(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
	return (0);
}

void	make_wall(t_data *data)
{
	data->window = mlx_new_window(data->mlx, 600, 600, "Cub3D");
	data->img = mlx_new_image(data->mlx, data->img_width, data->img_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	if (put_texture_in_struc(data))
		return ;
	mlx_hook(data->window, 17, 1L << 5, ft_destroy_windows, data);
	mlx_loop_hook(data->mlx, loop_create_wall, data);
	mlx_hook(data->window, 2, 1L << 0, key_pressed, data);
	mlx_hook(data->window, 3, 1L << 1, key_released, data);
	mlx_hook(data->window, 17, 0, ft_destroy_windows, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2 || ac > 2)
		return (ft_print_error("Error\n Probleme d'arguments", NULL));
	if (is_av1_legit(av[1]))
		return (1);
	data.av = av[1];
	innit_values(&data);
	read_map(&data);
	if (parsing_main(&data))
		return (1);
	data.player_x += 0.5;
	data.player_y += 0.5;
	make_wall(&data);
	return (0);
}
