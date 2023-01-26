

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mlx.h>

# define KEY_ESCAPE 49
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_UP 13
# define KEY_DOWN 1

const int WIDTH = 800;
const int HEIGHT = 600;
const int FOV = 90;




// int	key_pressed(int keycode, t_data *data)
// {
// 	printf("This is keycode: %d\n", keycode);
// 	if (keycode == 53)
// 		ft_destroy_windows(data);
// 	if (keycode == 13)
// 		ft_upward(data);
// 	if (keycode == 1)
// 		ft_downward(data);
// 	if (keycode == 2)
// 		ft_right(data);
// 	if (keycode == 0)
// 		ft_left(data);
// 	return (0);
// }




int map[10][10] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

double playerX = 5;
double playerY = 5;
double playerA = 0;

int main(void) {
    void *mlx_ptr;
    void *win_ptr;
    int *img_ptr;
    int bpp;
    int size_line;
    int endian;
    
    // Initialize minilibx
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Raycasting");
    img_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
    //int *data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian); // ancienne ligne
    char *data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
    

    //Main loop
    while(1) {
        //For each column of the screen
        for(int x = 0; x < WIDTH; x++) {
            //compute the projected ray angle into world space
            double cameraX = 2 * x / (double) WIDTH - 1;
            double rayDirX = playerA + FOV * cameraX;
            double rayDirY = playerA + FOV * cameraX;
            
            //which box of the map we're in
            int mapX = (int) playerX;
            int mapY = (int) playerY;
            
            //length of ray from current position to next x or y-side
            double sideDistX;
            double sideDistY;
            
            //length of ray from one x or y-side to next x or y-side
            double deltaDistX = fabs(1 / rayDirX);
            double deltaDistY = fabs(1 / rayDirY);
            double perpWallDist;
            
            //what direction to step in x or y-direction (either +1 or -1)
            int stepX;
            int stepY;
            
            int hit = 0; //was there a wall hit?
            int side; //was a NS or a EW wall hit?
            
            //Figure out the step direction and initial distance to a side
            if (rayDirX < 0) {
                stepX = -1;
                sideDistX = (playerX - mapX) * deltaDistX;
            } else {
                stepX = 1;
                sideDistX = (mapX + 1.0 - playerX) * deltaDistX;
            }
            if (rayDirY < 0) {
                stepY = -1;
                sideDistY = (playerY - mapY) * deltaDistY;
            } else {
                stepY = 1;
                sideDistY = (mapY + 1.0 - playerY) * deltaDistY;
            }
            //Perform DDA
            while (hit == 0) {
                //jump to next map square, OR in x-direction, OR in y-direction
                if (sideDistX < sideDistY) {
                    sideDistX += deltaDistX;
                    mapX += stepX;
                    side = 0;
                } else {
                    sideDistY += deltaDistY;
                    mapY += stepY;
                    side = 1;
                }
                //Check if ray has hit a wall
                if (map[mapX][mapY] > 0) hit = 1;
            }
            //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
            if (side == 0) perpWallDist = (mapX - playerX + (1 - stepX) / 2) / rayDirX;
            else perpWallDist = (mapY - playerY + (1 - stepY) / 2) / rayDirY;
            
            //Calculate height of line to draw on screen
            int lineHeight = abs((int)(HEIGHT / perpWallDist));
            
            //calculate lowest and highest pixel to fill in current stripe
            int drawStart = -lineHeight / 2 + HEIGHT / 2;
            if(drawStart < 0) drawStart = 0;
            int drawEnd = lineHeight / 2 + HEIGHT / 2;
            if(drawEnd >= HEIGHT) drawEnd = HEIGHT - 1;
            
            //choose wall color
            int color = 0xFF0000;
            if (side == 1) color = 0x00FF00;
            
            //give x and y sides different brightness
            if (side == 0) color = color / 2;
            
            //draw the pixels of the stripe as a vertical line
            for(int y = drawStart; y < drawEnd; y++) {
                data[y * WIDTH + x] = color;
            }
        }
        //mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
        
        // handle inputs
        //int key = mlx_get_key(mlx_ptr, win_ptr);
        // mlx_hook(data->window, 2, 1L << 0, key_pressed, data);
        // if(key == KEY_ESCAPE) break;
        // if(key == KEY_LEFT) playerA -= 0.05;
        // if(key == KEY_RIGHT) playerA += 0.05;
        // if(key == KEY_UP) {
        //     playerX += cos(playerA);
        //     playerY += sin(playerA);
        // }
        // if(key == KEY_DOWN) {
        //     playerX -= cos(playerA);
        //     playerY -= sin(playerA);
        // }
    }
    // Cleanup
    //mlx_destroy_window(mlx_ptr, win_ptr);
    return 0;
}
