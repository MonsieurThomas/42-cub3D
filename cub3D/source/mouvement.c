#include "../include/struc.h"

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == 49)
		data->moveSpeed = 0.1;
	if (keycode == 53)
		data->kill_win = 1;
	if (keycode == 13 || keycode == 17)
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
    if (keycode == 53 || keycode == 8)
        ft_destroy_windows(data);
	return (0);
}

int     mouvement(t_data *data)
{
    if (data->forward)
    {
        if(data->map[(int)(floor(data->posX + data->dirX * data->moveSpeed))][(int)floor(data->posY)] == '0')
            data->posX += data->dirX * data->moveSpeed;
        if(data->map[(int)floor((data->posX))][(int)floor((data->posY + data->dirY * data->moveSpeed))] == '0')
            data->posY += data->dirY * data->moveSpeed;
    }
    if (data->backward)
    {
        if(data->map[(int)(floor(data->posX - data->dirX * data->moveSpeed))][(int)floor(data->posY)] == '0') 
            data->posX -= data->dirX * data->moveSpeed;
        if(data->map[(int)floor((data->posX))][(int)floor((data->posY - data->dirY * data->moveSpeed))] == '0')
            data->posY -= data->dirY * data->moveSpeed;
    }
	if (data->leftward)
	{
		if (data->map[(int)(floor((data->posX - data->dirY * data->moveSpeed)))][(int)(floor(data->posY))] == '0')
			data->posX -= data->dirY * data->moveSpeed / 1.5;
		if (data->map[(int)(floor(data->posX))][(int)(floor((data->posY + data->dirX * data->moveSpeed)))] == '0')
			data->posY += data->dirX * data->moveSpeed / 1.5;
	}
	if (data->rightward)
	{
		if (data->map[(int)floor((data->posX + data->dirY * data->moveSpeed))][(int)floor(data->posY)] == '0')
			data->posX += data->dirY * data->moveSpeed / 1.5;
		if (data->map[(int)(floor(data->posX))][(int)floor((data->posY - data->dirX * data->moveSpeed))] == '0')
			data->posY -= data->dirX * data->moveSpeed / 1.5;
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
