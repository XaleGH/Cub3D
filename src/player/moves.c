/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:54:25 by thsion            #+#    #+#             */
/*   Updated: 2025/02/07 15:28:12 by thsion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	init_p_angle(t_data *data, char dir)
{
	if (dir == 'N')
		data->player.p_angle = 3 * PI / 2;
	if (dir == 'S')
		data->player.p_angle = PI / 2;
	if (dir == 'E')
		data->player.p_angle = 0;
	if (dir == 'W')
		data->player.p_angle = PI;
}

void	init_player(t_data *data, int x, int y)
{
	data->player.map_x = x;
	data->player.map_y = y;
	data->player.p_x = x * TILE_SIZE + TILE_SIZE / 2;
	data->player.p_y = y * TILE_SIZE + TILE_SIZE / 2;
	data->player.p_speed = 10;
	data->player.fov_rad = (FOV * PI / 180);
	init_p_angle(data, data->map[y][x]);
}
