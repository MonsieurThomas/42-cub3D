/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:21:03 by rthomas           #+#    #+#             */
/*   Updated: 2023/04/20 20:09:20 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../gnl/get_next_line.h"
# include "../mlx/mlx.h"
# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

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
	int				k;
	int				f;

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

	double			player_x;
	double			player_y;

	double			main_dir_x;
	double			main_dir_y;

	double			fov_x;
	double			fov_y;

	double			time;
	double			old_time;
	double			w;
	double			move_speed;
	double			rot_speed;
	double			ratio;
	double			rotspeed;

	double			camera_plane;
	double			ray_x;
	double			ray_y;

	int				map_x;
	int				map_y;

	double			predelta_x;
	double			predelta_y;

	double			delta_x;
	double			delta_y;

	double			perp_wall;

	int				wich_side_x;
	int				wich_side_y;

	int				hit;
	int				is_frontal;

	int				line_height;

	int				draw_start;
	int				draw_end;
	int				x;
	int				y;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;

	int				kill_win;
	int				forward;
	int				backward;
	int				rightward;
	int				leftward;
	int				rot_right;
	int				rot_left;

	t_texture		texture[4];
	int				imgsiz;
	double			texture_x;
	int				pixel_x;
	int				pixel_y;
	double			draw_step;
	double			actual_step;

	int				jmax;
	int				div_x;
	int				div_y;
	int				deb_x;
	int				deb_y;

	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				wall;
	int				error;
	int				parsing_main_loop;
	char			wall_extra;
	char			color_c;
	char			color_f;
	int				f1;
	int				f2;
	int				f3;
	int				c1;
	int				c2;
	int				c3;
	int				ceil_color;
	int				floor_color;
	int				texture_num;
	char			player_pov;
	int				player_nb;
	int				is_map;
	int				is_changed;
}					t_data;

void				raycasting(t_data *data);
int					mouvement(t_data *data);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
unsigned int		get_color_texture(t_data *data, int x, int y, int nb);
int					parsing_main(t_data *data);
int					ft_print_error(char *str, char *arg);
int					is_av1_legit(char *av);
int					put_texture_in_struc(t_data *data);
void				innit_values(t_data *data);
int					mouvement(t_data *data);
void				show_minimap(t_data *data);
int					get_nb_line(t_data *data);
int					read_map(t_data *data);
int					key_released(int keycode, t_data *data);
int					key_pressed(int keycode, t_data *data);
int					ft_print_error(char *str, char *arg);
int					ft_destroy_windows(t_data *data);
int					get_textu_addr(t_data *data);
unsigned int		get_color_textu(t_data *data, int x, int y, int nb);
int					get_color(t_data *data, int i);
int					color_to_struct(t_data *data, char **tab, char letter);
int					put_wall_in_struct(t_data *data, int i);
int					is_color_legit(t_data *data, char letter);
void				free_tab(char **tab);
void				change_player_pov(t_data *data);
int					where_is_player(t_data *data);
int					create_new_map(t_data *data, int i);
int					is_beginning_of_map(t_data *data, int i);
int					check_around_each_zero(t_data *data, int i, int j);
int					check_whole_frontier(t_data *data);
void				perpwall_and_drawing(t_data *data);
void				choose_texture(t_data *data);
void				tab_to_space(t_data *data);
int					nb_commas(char *str);
char				**secure_split(char *s, char c);

#endif