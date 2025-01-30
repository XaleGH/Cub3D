#include "../../inc/cub3d.h"

double	normalize_angle(double angle)
{
	if (angle < 0)
		angle += (2 * PI);
	if (angle > (2 * PI))
		angle -= (2 * PI);
	return (angle);
}

double	get_first_step(t_data *data, char dir)
{
	if (dir == 'H')
	{
		if (data->ray.r_angle < PI)
			return ((data->player.p_y / TILE_SIZE) * TILE_SIZE + TILE_SIZE);
		if (data->ray.r_angle > PI)
			return ((data->player.p_y / TILE_SIZE) * TILE_SIZE);
	}
	if (dir == 'V')
	{
		if (data->ray.r_angle > PI / 2 && data->ray.r_angle < 3 * PI / 2)
			return ((data->player.p_x / TILE_SIZE) * TILE_SIZE);
		if (data->ray.r_angle < PI / 2 || data->ray.r_angle > 3 * PI / 2)
			return ((data->player.p_x / TILE_SIZE) * TILE_SIZE + TILE_SIZE);
	}
	return (0);
}

double	get_inter(t_data *data, char dir)
{
	if (dir == 'H')
	{
		if (data->ray.r_angle < PI)
			return (TILE_SIZE);
		if (data->ray.r_angle > PI)
			return (-TILE_SIZE);
	}
	if (dir == 'V')
	{
		if (data->ray.r_angle > PI / 2 && data->ray.r_angle < 3 * PI / 2)
			return (-TILE_SIZE);
		if (data->ray.r_angle < PI / 2 || data->ray.r_angle > 3 * PI / 2)
			return (TILE_SIZE);
	}
	return (0);
}