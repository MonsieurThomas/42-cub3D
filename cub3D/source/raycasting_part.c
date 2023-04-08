#include "../include/struc.h"

void	draw_line(t_data *data)
{
    // init dir en fonction du mur
    if (data->side == 0)
		data->wallX = data->posY + data->perpWallDist * data->rayDirY; // wallX est l'endroit exact du ray sur lequel une ligne y doit etre dessiné
	else
		data->wallX = data->posX + data->perpWallDist * data->rayDirX; // le calcul est different si le mur est de face ou non 
	data->wallX -= floor(data->wallX);
    data->texX = (int)(data->wallX * 64); // calcul de la juste ligne de la texture qui doit etre copié
    data->step = (double)64 / data->lineHeight; // data->step est la distance a faire pour garder coherence avec la texture dans la boucle, en fonction de l'angle du mur
    data->texPos = (data->drawStart + data->lineHeight / 2 - data->img_height / 2) * data->step; // position actuelle dans la
    int color;
    while (data->drawStart <= data->drawEnd)
	{
		data->texY = (int)data->texPos % 64; // emplacement dans la texture sur l'axe Y.
		data->texPos += data->step; //avancement par step en fonction de l'angle et de la distance du mur
		color = get_color_textu(data, data->texX, data->texY, data->textureNum); // 0 = textdir
		my_mlx_pixel_put(data, data->x, data->drawStart, color);
		data->drawStart++;
	}

}

void     chooseTexture(t_data *data)
{
    if (data->side == 0 && data->rayDirX < 0)
		data->textureNum = 0;
	if (data->side == 0 && data->rayDirX >= 0)
		data->textureNum = 1;
	if (data->side == 1 && data->rayDirY < 0)
		data->textureNum = 2;
	if (data->side == 1 && data->rayDirY >= 0)
		data->textureNum = 3;

}

void    perpWallDist_and_drawing(t_data *data)
{
    if (data->side == 0)
    {
        data->perpWallDist = ((double)data->mapX - data->posX + (1 - (double)data->stepX) / 2) / data->rayDirX;
        // double c = data->mapX - data->posX;
        // printf("this is (1 - (double)data->stepX) / 2) = %f\n", c);
        // (1 - (double)data->stepX) / 2 cette partie toujours 0 ou 1
        // position actuelle du joueur sur l'axe X
        // en divisant la distance horizontale par la composante x de la direction du rayon (data->rayDirX), on obtient la distance perpendiculaire entre le joueur et le mur.
    }
    else
        data->perpWallDist = ((double)data->mapY - data->posY + (1 - (double)data->stepY) / 2) / data->rayDirY;
    chooseTexture(data);
    data->lineHeight = ((double)data->img_height * data->ratio / data->perpWallDist);
    data->drawStart = -data->lineHeight / 2 + data->img_height / 2; // divise l'ecran / 2 et addtionne  - la longueur longeur de la ligne pour que la ligne soit centré
    // drawStart est le debut du mur
    if(data->drawStart < 0) // previent les explosions
        data->drawStart = 0;
    data->drawEnd = data->lineHeight / 2 + data->img_height / 2; // drawEnd est la fin du mur
    if(data->drawEnd >= data->img_height)
        data->drawEnd = data->img_height - 1;
    //int abc = (255 << 16) | (126 << 8) | (1);
    for(int y = 0; y < data->drawStart; y++) // colorie le plafond
        my_mlx_pixel_put(data, data->x, y, data->ceil_color); 
    // for(int y = data->drawStart; y < data->drawEnd; y++)
    // {
    //     int color = get_color_textu(data, data->x, y, 0);
    //     my_mlx_pixel_put(data, data->x, y, color); // 0xFF0000
    // }
    draw_line(data);
    if (data->drawEnd > 0)
        for(int y = data->img_height - 1; y > data->drawEnd; y--) // colorie le sol
            my_mlx_pixel_put(data, data->x, y, data->floor_color);
}

void getting_sidedists(t_data *data)
{
    //printf("this is data->rayDirX = %f\n", data->rayDirX);
    if (data->rayDirX < 0) {
                data->stepX = -1; // stepX est le cote du mur ou chercher la colision, si rayDirX < 0 ca veut dire que le rayon part vers la gauche
                data->sideDistX = (data->posX - data->mapX) * data->deltaDistX; // distance avant prochaine impact avec l'axe X de la carte
                // posX et mapX ne changent a pas chaque calcul de rayon, deltaDist change
                // mapX est un nombre entier, posX est la position du joueur dans la case du nombre entier, donc toujours un peu superieur
    } 
    else
    {
        data->stepX = 1;
        data->sideDistX = (data->mapX + 1.0 - data->posX) * data->deltaDistX; // calcul horizontal, on ajoute +1 pour connaitre la distance entre la position du joueur et la prochaine ligne horizontale de la carte
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
}

void getting_deltas(t_data *data)
{
    data->deltaDistX = 0; // delta entre le croisement de passage a travers 2 lignes X par le rayon,
    data->deltaDistY = 0;
    // if (data->rayDirX == 0)
    //     data->deltaDistY = 0;
    // else if (data->rayDirX == 1)
    //     data->deltaDistY = 1;
    // else
        data->deltaDistY = sqrt(1 + (data->rayDirX * data->rayDirX) / (data->rayDirY * data->rayDirY)); //
        // parce que (1 / (x/y)^2) quand on parcour 1 x, on a parcouru y/x en distance en y
    // if (data->rayDirY == 0)
    //     data->deltaDistX = 0;
    // else if (data->rayDirY == 1)
    //     data->deltaDistX = 1;
    // else
        data->deltaDistX = sqrt(1 + (data->rayDirY * data->rayDirY) / (data->rayDirX * data->rayDirX));
}

void is_hit (t_data *data)
{
    if (data->sideDistX < data->sideDistY)
    {
        data->sideDistX += data->deltaDistX;
        data->mapX += data->stepX;
        data->side = 0; //  = 0 si collision sur l'axe X, egale 1 si collision sur l'axe Y.
    }
    else
    {
        data->sideDistY += data->deltaDistY;
        data->mapY += data->stepY;
        data->side = 1;
    }
    if (data->map[data->mapX][data->mapY] == '1') // on Loop en avancant d'une case comme un serpent, le seul vrai projet est de se decaler de la bonne case pour suivre le rayon et pouvoir le suivre avec data->map
        data->hit = 1;
}

void raycasting (t_data *data)
{
    data->x = 0;       
    while(data->x < data->img_width)
    {
        data->cameraX = 2 * data->x / (double) data->img_width - 1; // camera x = entre 0 et 1, x2 = entre 0 et 2, -1 = entre -1 et 1; left = -1, center = 0, right = 1;
        data->rayDirX = data->dirX + data->planeX * data->cameraX; // planeX initialisé a 0, change avec les rotations, represente l'axeX, c'est a dire la camera et probablement perpWallDist quand un mur est de face
        // dirX est la direction du joueur, dirX et movespeed le font avancer, et donc change posX
        data->rayDirY = data->dirY + data->planeY * data->cameraX; // planeY initialisé a 0.66 parce que Lodev, contribue au FOV
        // printf("%f\n",data->planeY); // 
        // printf("this is data->dirX = %f\n", data->dirX);
        // printf("this is data->dirX = %f\n", data->dirY);
        // printf("this is data->planeX = %f\n", data->planeX);
        // printf("this is data->planeY = %f\n\n\n", data->planeY);
        data->mapX = (int) data->posX; // chaque case dans laquelle on va voir s'il y a un mur, initialisé avec la position actuelle du joueur 
        data->mapY = (int) data->posY; // voir au dessus
        
        getting_deltas(data);
        getting_sidedists(data);
        
        data->hit = 0; // hit = impact avec un mur
        //printf("this is delta dist X outside = %f\n", data->deltaDistX);
        while (data->hit == 0)
            is_hit(data);
        perpWallDist_and_drawing(data);
        (data->x)++;
    }
}
