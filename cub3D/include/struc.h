/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:21:03 by rthomas           #+#    #+#             */
/*   Updated: 2023/01/13 12:42:08 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../gnl/get_next_line.h"
# include "libft.h"
# include <limits.h>
# include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# define ROTSPEED 0.1


typedef struct s_data
{
	int				i;
	int				j;

	char			*av;
	char			**map;

	void			*mlx;
	void			*window;
	int				window_x;
	int				window_y;
	char			*dst;
	char			*relative_path;
	double			img_width;
	double			img_height;

	// valeurs tuto
	
	double			posX;
	double			posY;
	
	double 			dirX;
	double 			dirY;

	double 			planeX;
	double 			planeY;
	
	double			time;
	double			oldTime;
	double			w;
	double			moveSpeed;
	double			rotSpeed;
	double			ratio;

	double			cameraX;
	double			rayDirX;
	double			rayDirY;

	int				mapX;
	int				mapY;
	
	double 			sideDistX;
    double 			sideDistY;
            
    double 			deltaDistX;
    double 			deltaDistY;

	double 			perpWallDist;
            
	int 			stepX;
	int 			stepY;
	
	int 			hit;
	int 			side;

	int				lineHeight;
	
	// impression

	int				drawStart;
	int				drawEnd;
	int				x;
	int				y;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				blackColor;
	
	// mouvement

	int				kill_win;
	int				forward;
	int				backward;
	int				rightward;
	int				leftward;
	int				rot_right;
	int				rot_left;

}					t_data;

#endif