/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainthomas <romainthomas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:10:16 by rthomas           #+#    #+#             */
/*   Updated: 2023/01/29 16:33:49 by romainthoma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/struc.h"

int     mouvement(t_data *data);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}


int	key_pressed(int keycode, t_data *data)
{
	if (keycode == 49)
		data->moveSpeed = 0.1;
	if (keycode == 53)
		data->kill_win = 1;
	if (keycode == 13)
		data->forward = 1;
	if (keycode == 1)
		data->backward = 1;
	if (keycode == 2)
		data->rightward = 1;
	if (keycode == 0)
		data->leftward = 1;
	if (keycode == 123)
		data->rot_left = 1;
	if (keycode == 124)
		data->rot_right = 1;
	return (0);
}

int	key_released(int keycode, t_data *data)
{
	if (keycode == 49)
		data->moveSpeed = 0.05;
	if (keycode == 53)
		data->kill_win = 0;
	if (keycode == 13)
		data->forward = 0;
	if (keycode == 1)
		data->backward = 0;
	if (keycode == 2)
		data->rightward = 0;
	if (keycode == 0)
		data->leftward = 0;
	if (keycode == 123)
		data->rot_left = 0;
	if (keycode == 124)
		data->rot_right = 0;
	return (0);
}


int	get_nb_line(t_data *data)
{
	int		fd;
	int		nb_line;
	char	*line;

	fd = open(data->av, O_RDONLY);
	nb_line = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		nb_line++;
	}
	free(line);
	close(fd);
	return (nb_line);
}

int	read_map(t_data *data)
{
	int		fd;
	int		nb_line;
	char	*line;

	nb_line = get_nb_line(data);
	fd = open(data->av, O_RDONLY);
	data->map = (char **)malloc(sizeof(char *) * (nb_line + 1));
	data->map[nb_line] = NULL;
	data->i = 0;
	while (data->i < nb_line)
	{
		line = get_next_line(fd);
		data->map[data->i] = ft_strdup(line);
		if (data->map[data->i][ft_strlen(line) - 1] == '\n')
			data->map[data->i][ft_strlen(line) - 1] = 0;
		free(line);
		data->i++;
	}
	if (data->i < 3)
	{
		ft_putstr_fd("Error\nProbleme de carte\n", 1);
		return (0);
	}
	close(fd);
	return (1);
}

// void    show_minimap(t_data *data, int i, int j)
// {
//     void *mlx;
//     void *win;
    
//     mlx = mlx_init();
//     win = mlx_new_window(mlx, 600, 600, "fenetre");
    
//     int x = 450;
//     int y = 450;
    
//     int x_part = 0;
//     int y_part = 0;

//     int x_actual = 100 / j;
//     int y_actual = 100 / i;
    
//     // printf("this is x_actual = %d\n", x_actual);
//     // printf("this is y_actual = %d\n", y_actual);
//     // printf("this is (x/x_actual) = %d\n", (x_part/x_actual));
//     // printf("this is (x/x_actual) = %d\n", (y_part/y_actual));
//     // printf("this is calcul = %d\n", 199 / 50);
    
//      while ((x + x_part) < 549)
//     {
//         y_part = 0;
//         while ((y + y_part) < 549)
//         {
//             // printf("this is (x/x_actual) = %d\n", (x_part/x_actual));
//             // printf("this is (x_part) = %d\n", (x_part));
//             // printf("this is (x_actual) = %d\n", (x_actual));
//             // printf("---\n");
//             // printf("this is (y/y_actual) = %d\n", (y_part/y_actual));
//             // printf("this is (y_part) = %d\n", (y_part));
//             // printf("this is (y_actual) = %d\n", (y_actual));
//             if ((i - 1 >= (y_part/y_actual)) && (j - 1 >= (x_part/x_actual)))
//                 if ((data->map[(y_part/y_actual)][(x_part/x_actual)]) == '1')
//                     mlx_pixel_put(mlx, win, (x + x_part), (y + y_part), 0xFF0000);
//             y_part++;
//         }
//         x_part++;
//     }
//     mlx_loop(mlx);
// }

void raycasting (t_data *data)
{
        for(data->x = 0; data->x < data->img_width; (data->x)++)
        {
            data->cameraX = 2 * data->x / (double) data->img_width - 1;
            data->rayDirX = data->dirX + data->planeX * data->cameraX;
            data->rayDirY = data->dirY + data->planeY * data->cameraX;
            
            data->mapX = (int) data->posX;
            data->mapY = (int) data->posY;
            

            data->deltaDistX = 0;
            data->deltaDistY = 0;
            
            if (data->rayDirX == 0)
                data->deltaDistY = 0;
            else if (data->rayDirX == 1)
                data->deltaDistY = 1;
            else
                data->deltaDistY = sqrt(1 + (data->rayDirX * data->rayDirX) / (data->rayDirY * data->rayDirY));

            if (data->rayDirY == 0)
                data->deltaDistX = 0;
            else if (data->rayDirY == 1)
                data->deltaDistX = 1;
            else
                data->deltaDistX = sqrt(1 + (data->rayDirY * data->rayDirY) / (data->rayDirX * data->rayDirX));
            
            data->hit = 0;
            if (data->rayDirX < 0) {
                data->stepX = -1;
                data->sideDistX = (data->posX - data->mapX) * data->deltaDistX;
            } 
            else
            {
                data->stepX = 1;
                data->sideDistX = (data->mapX + 1.0 - data->posX) * data->deltaDistX;
            }
            if (data->rayDirY < 0)
            {
                data->stepY = -1;
                data->sideDistY = (data->posY - data->mapY) * data->deltaDistY;
            }
            else
            {
                data->stepY = 1;
                data->sideDistY = (data->mapY + 1.0 - data->posY) * data->deltaDistY;
            }

            while (data->hit == 0) {
                if (data->sideDistX < data->sideDistY)
                {
                    data->sideDistX += data->deltaDistX;
                    data->mapX += data->stepX;
                    data->side = 0;
                }
                else
                {
                    data->sideDistY += data->deltaDistY;
                    data->mapY += data->stepY;
                    data->side = 1;
                }
                if (data->map[data->mapX][data->mapY] == '1')
                {
                    data->hit = 1;
                }
            }

            if (data->side == 0)
            {
                data->perpWallDist = ((double)data->mapX - data->posX + (1 - (double)data->stepX) / 2) / data->rayDirX;
            }
            else
                data->perpWallDist = ((double)data->mapY - data->posY + (1 - (double)data->stepY) / 2) / data->rayDirY;
            data->lineHeight = ((double)data->img_height * data->ratio / data->perpWallDist);
            
            data->drawStart = -data->lineHeight / 2 + data->img_height / 2;
            if(data->drawStart < 0)
                data->drawStart = 0;
            data->drawEnd = data->lineHeight / 2 + data->img_height / 2;
            if(data->drawEnd >= data->img_height)
                data->drawEnd = data->img_height - 1;
            for(int y = 0; y < data->drawStart; y++)
                my_mlx_pixel_put(data, data->x, y, 0);
            for(int y = data->drawStart; y < data->drawEnd; y++)
                my_mlx_pixel_put(data, data->x, y, 0xFF0000);
                //printf("this is data->drawEnd: %d\n", data->drawEnd);
            if (data->drawEnd > 0)
                for(int y = data->img_height - 1; y > data->drawEnd; y--)
                    my_mlx_pixel_put(data, data->x, y, 0);
        }
    }

    int loop_create_wall(t_data *data)
    {
        raycasting(data);
        mouvement(data);
        mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
        return (0);
    }

int     mouvement(t_data *data)
{
    if (data->forward)
    {
        printf("We are in forward\n");
        if(data->map[(int)(floor(data->posX + data->dirX * data->moveSpeed))][(int)floor(data->posY)] == '0')
            data->posX += data->dirX * data->moveSpeed;
        if(data->map[(int)floor((data->posX))][(int)floor((data->posY + data->dirY * data->moveSpeed))] == '0')
            data->posY += data->dirY * data->moveSpeed;
    }
    if (data->backward)
    {
        printf("We are in backward\n");
        if(data->map[(int)(floor(data->posX - data->dirX * data->moveSpeed))][(int)floor(data->posY)] == '0') 
        {
            printf("We are in 1, this is the result = %f\n", data->dirX * data->moveSpeed);
            data->posX -= data->dirX * data->moveSpeed;
        }
        if(data->map[(int)floor((data->posX))][(int)floor((data->posY - data->dirY * data->moveSpeed))] == '0')
        {
            printf("We are in 2, this is the result = %f\n", data->dirY * data->moveSpeed);
            data->posY -= data->dirY * data->moveSpeed;
        }
    }
    if (data->leftward)
    {
        printf("We are in leftward\n");
        if (data->map[(int)(floor((data->posX - data->dirY * data->moveSpeed)))][(int)(floor(data->posY))] == '0')
	    	data->posX -= data->dirY * data->moveSpeed / 2;
	    if (data->map[(int)(floor(data->posX))][(int)(floor((data->posY + data->dirX * data->moveSpeed)))] == '0')
	    	data->posY += data->dirX * data->moveSpeed / 2;
    }
    if (data->rightward)
    {
        printf("We are in rightward\n");
        if (data->map[(int)floor((data->posX + data->dirY * data->moveSpeed))][(int)floor(data->posY)] == '0')
            data->posX += data->dirY * data->moveSpeed / 2;
        if (data->map[(int)(floor(data->posX))][(int)floor((data->posY - data->dirX * data->moveSpeed))] == '0')
            data->posY -= data->dirX * data->moveSpeed / 2;
    }

    if (data->rot_left)
    {
        double	temp;

        temp = data->dirX;
        data->dirX = data->dirX * cos(ROTSPEED / 2) - data->dirY * sin(ROTSPEED / 2);
        data->dirY = temp * sin(ROTSPEED / 2) + data->dirY * cos(ROTSPEED / 2);
        temp = data->planeX;
        data->planeX = data->planeX * cos(ROTSPEED / 2) - data->planeY * sin(ROTSPEED / 2);
        data->planeY = temp * sin(ROTSPEED / 2) + data->planeY * cos(ROTSPEED / 2);
    }
    
    if (data->rot_right)
    {
        double	temp;

        temp = data->dirX;
        data->dirX = data->dirX * cos(-ROTSPEED / 2) - data->dirY * sin(-ROTSPEED / 2);
        data->dirY = temp * sin(-ROTSPEED / 2) + data->dirY * cos(-ROTSPEED / 2);
        temp = data->planeX;
        data->planeX = data->planeX * cos(-ROTSPEED / 2) - data->planeY * sin(-ROTSPEED / 2);
        data->planeY = temp * sin(-ROTSPEED / 2) + data->planeY * cos(-ROTSPEED / 2);
    }
    
    return (0);
}

void make_wall(t_data *data)
{
    data->mlx = mlx_init();
    data->window = mlx_new_window(data->mlx, 600, 600, "Cub3D");
    //mlx_pixel_put(data->mlx, data->window, 300, 300, 0xFF0000);
    data->img = mlx_new_image(data->mlx, data->img_width, data->img_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
    mlx_hook(data->window, 2, 1L << 0, key_pressed, data);
	mlx_hook(data->window, 3, 1L << 1, key_released, data);
    mlx_loop_hook(data->mlx, loop_create_wall, data);
    //mlx_hook(data->window, 2, 1L << 0, key_pressed, data);
    mlx_loop(data->mlx);
}

int main(int ac, char **av)
{
    t_data data;
   
    (void)ac;

    data.av = av[1];
    read_map(&data);
    int i = 0;
    int j = 0;
    //printf("this is data[0][0] = %c\n", data.map[0][0]);
    // printf("this is data->i = %d\n", data.i);
    // printf("this is data->j = %d\n", data.j);
    if (ac < 2)
    {
        printf("no map\n");
        return 0;
    }
    while (i < data.i)
    {
        printf("%c", data.map[i][j]);
        j = 0;
        while(data.map[i][j])
        {
            printf("%c", data.map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }  
    // printf("this is i = %d\n", i);
    // printf("this is j = %d\n", j);
    
    //show_minimap(&data, i, j);
    data.img_width = 600;
    data.img_height = 600;
    data.posX = 2.0;
    data.posY = 2.0;
    data.dirX = -1.0;
    data.dirY = 0.0;
    data.planeX = 0.0;
    data.planeY = 0.66; 
    data.ratio =((double)data.img_width / (double)data.img_height) / (4.0 / 3.0);
    data.moveSpeed = 0.08;
    data.time = 0; 
    data.oldTime = 0;
    data.w = 600;
    data.blackColor = 7777777;
    
    make_wall(&data);
    return (0);
}



