/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainthomas <romainthomas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:21:03 by rthomas           #+#    #+#             */
/*   Updated: 2023/04/08 20:32:14 by romainthoma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../gnl/get_next_line.h"
# include "libft.h"
# include <limits.h>
# include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# define ROTSPEED 0.1 // reinclure avec les valeurs normales

typedef struct s_texture
{
	void		*mlx_win;
	void		*mlx;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_texture;

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
	int				img_width;
	int				img_height;

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

	// affichage

	t_texture		texture[4];
	int				imgsiz; // changer nom
	double			wallX;
	int				texX;
	int				texY;
	double			step;
	double			texPos;
	
	// minimap

	int				jmax;
	int				divX;
	int				divY;
	int				debX;
	int				debY;

	/// parsing

	int				isWall;
	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
	int				wall;
	int				error;
	char			wallExtra;
	char			colorC;
	char			colorF;
	int				f1;
	int				f2;
	int				f3;
	int				c1;
	int				c2;
	int				c3;
	int				ceil_color;
	int				floor_color;
	int				textureNum;
	char			playerPOV;
	
}					t_data;


void					raycasting (t_data *data);
int						mouvement(t_data *data);
void					my_mlx_pixel_put(t_data *data, int x, int y, int color);
unsigned int			get_color_textu(t_data *data, int x, int y, int nb); // changer Nom
int						parsing_main(t_data *data);
int						ft_print_error(char *str, char *arg);
int						is_av1_legit(char *av);
int						put_texture_in_struc(t_data *data);
void					innit_values(t_data *data);
int						mouvement(t_data *data);
void					show_minimap(t_data *data);
int						get_nb_line(t_data *data);
int						read_map(t_data *data);
int						key_released(int keycode, t_data *data);
int						key_pressed(int keycode, t_data *data);
int						ft_print_error(char *str, char *arg);
int						ft_destroy_windows(t_data *data);
void					get_textu_addr(t_data *data);
unsigned int			get_color_textu(t_data *data, int x, int y, int nb);
int						get_color(t_data *data, int i);
int 					color_to_struct(t_data *data, char **tab, char letter);
int						put_wall_in_struct(t_data *data, int i);
int						is_color_legit(t_data *data, char letter);
void					free_tab(char **tab);
void					change_player_POV(t_data *data);
int						where_is_player(t_data *data);
int						create_new_map(t_data *data, int i);
int						is_beginning_of_map(t_data *data, int i);


#endif