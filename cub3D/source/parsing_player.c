/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainthomas <romainthomas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:18:35 by romainthoma       #+#    #+#             */
/*   Updated: 2023/04/08 19:24:11 by romainthoma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/struc.h"

int where_is_player(t_data *data)
{
    int i = 0;
    int j = 0;
    int playerNb = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || data->map[i][j] =='E' || data->map[i][j] == 'W')
            {
                data->playerPOV = data->map[i][j]; // Je garde le char en reserve parce que je dois m'en servir pour orienter la camera
                data->map[i][j] = '0'; // je remplace la lettre du joueur par '0'
                data->posX = i;
                data->posY = j;
                playerNb++;
            }
            j++;
        }
        i++;
    }

    if (playerNb != 1)
        return (ft_print_error("Error\nProbleme de joueur", NULL));
    return (0);
}


void change_player_POV(t_data *data)
{
    // Il n'y a pas le N parce que les valeurs par defaut affiche la camera vers le nord
	if (data->playerPOV == 'S')
	{
		data->dirX = 1;
        data->planeY = -0.66;
	}
	if (data->playerPOV == 'W') // Pour le reste je suis incapable d'expliquer pourquoi ces valeurs fonctionne, j'ai tout trouvé empiriquement et c'etait une guerre sans nom
    // Je t'invite a essayer de changer quoi que ce soit pour voir, tout l'affichage explose, les touches s'inverse, c'est traumatique
	{
		data->dirY = -1;
		data->dirX = 0;
        data->planeX = -0.66;
        data->planeY = 0;
	}
	if (data->playerPOV == 'E')
	{
	    data->dirY = 1;
        data->planeX = 0.66;
        data->planeY = 0;
        data->dirX = 0;
	}
}