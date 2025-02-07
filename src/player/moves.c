#include "../../inc/cub3d.h"

void	rotate(t_data *data, int direction)
{
	if (direction == -1)
	{
		data->player.p_angle += data->delta_angle;
		if (data->player.p_angle > (2 * PI))
			data->player.p_angle -= (2 * PI);
	}
	if (direction == 1)
	{
		data->player.p_angle -= data->delta_angle;
		if (data->player.p_angle < 0)
			data->player.p_angle += (2 * PI);
	}
	mlx_destroy_image(data->mlx, data->img_screen.img);
	raycasting(data);
}

void	forward_or_back(t_data *data, int dir)
{
	int	new_x;
	int	new_y;

	new_x = data->player.p_x + floorf(data->player.p_speed
			* cos(data->player.p_angle)) * dir;
	new_y = data->player.p_y + floorf(data->player.p_speed
			* sin(data->player.p_angle)) * dir;
	if (data->map[new_y / TILE_SIZE][new_x / TILE_SIZE] != '1')
	{
		data->player.p_x = new_x;
		data->player.p_y = new_y;
    }
	mlx_destroy_image(data->mlx, data->img_screen.img);
	raycasting(data);
}

void	left_or_right(t_data *data, int dir)
{
	int	new_x;
	int	new_y;

	new_x = data->player.p_x + floorf(data->player.p_speed
			* cos(data->player.p_angle + dir * (PI / 2)));
	new_y = data->player.p_y + floorf(data->player.p_speed
			* sin(data->player.p_angle + dir * (PI / 2)));
	if (data->map[new_y / TILE_SIZE][new_x / TILE_SIZE] != '1')
	{
		data->player.p_x = new_x;
		data->player.p_y = new_y;
	}
	mlx_destroy_image(data->mlx, data->img_screen.img);
	raycasting(data);
}
