#include "../../inc/cub3d.h"

int	hit_wall(t_data *data, double x, double y, char flag)
{
	int	map_x;
	int	map_y;

	map_x = x / TILE_SIZE;
	if (flag == 'V' && data->ray.r_angle > PI / 2 && data->ray.r_angle < 3 * PI / 2)
		map_x = x / TILE_SIZE - 1;
	map_y = y / TILE_SIZE;
	if (flag == 'H' && data->ray.r_angle > PI)
		map_y = y / TILE_SIZE - 1;
	if (map_x < 0 || map_y < 0 || map_y >= data->nb_row || map_x >= (int)ft_strlen(data->map[map_y]))
		return (0);
	if (data->map[map_y][map_x] == '1')
		return (0);
	return (1);
}

double	get_horizontal_distance(t_data *data)
{
	double	h_x;
	double	h_y;
	double	inter_x;
	double	inter_y;

	data->ray.r_angle = normalize_angle(data->ray.r_angle);
	if (data->ray.r_angle == 0 || data->ray.r_angle == PI)
		return (0);
	h_y = get_first_step(data, 'H');
	h_x = (h_y - data->player.p_y) / tan(data->ray.r_angle) + data->player.p_x;
	inter_y = get_inter(data, 'H');
	inter_x = inter_y / tan(data->ray.r_angle);
	while (hit_wall(data, h_x, h_y, 'H') == 1)
	{
		h_x += inter_x;
		h_y += inter_y;
	}
	data->ray.horiz_x = h_x;
	data->ray.horiz_y = h_y;
	return (sqrt(pow(h_x - data->player.p_x, 2)
			+ pow(h_y - data->player.p_y, 2)));
}

double	get_vertical_distance(t_data *data)
{
	double	v_x;
	double	v_y;
	double	inter_x;
	double	inter_y;

	data->ray.r_angle = normalize_angle(data->ray.r_angle);
	if (data->ray.r_angle == PI / 2 || data->ray.r_angle == 3 * PI / 2)
		return (0);
	v_x = get_first_step(data, 'V');
	v_y = (v_x - data->player.p_x) * tan(data->ray.r_angle) + data->player.p_y;
	inter_x = get_inter(data, 'V');
	inter_y = inter_x * tan(data->ray.r_angle);
	while (hit_wall(data, v_x, v_y, 'V') == 1)
	{
		v_x += inter_x;
		v_y += inter_y;
	}
	data->ray.vert_x = v_x;
	data->ray.vert_y = v_y;
	return (sqrt(pow(v_x - data->player.p_x, 2)
			+ pow(v_y - data->player.p_y, 2)));
}

void	get_shorter_distance(t_data *data)
{
	double	h_distance;
	double	v_distance;

	h_distance = get_horizontal_distance(data);
	v_distance = get_vertical_distance(data);
	if (h_distance <= v_distance)
	{
		data->ray.r_distance = h_distance;
		data->ray.flag = 1;
	}
	else
	{
		data->ray.r_distance = v_distance;
		data->ray.flag = 0;
	}
}

void	raycasting(t_data *data)
{
	int ray;

	ray = 0;
	data->ray.r_angle = data->player.p_angle - (data->player.fov_rad / 2);
	data->img_screen.img = mlx_new_image(data->mlx, SCR_WIDTH, SCR_HEIGHT);
	data->img_screen.addr = mlx_get_data_addr(data->img_screen.img, &data->img_screen.bits_per_pixel, &data->img_screen.line_length, &data->img_screen.endian);
	while (ray < SCR_WIDTH)
	{
		get_shorter_distance(data);
		//display_wall(data, ray);//afaire
		ray++;
		data->ray.r_angle += data->player.fov_rad / SCR_WIDTH;
	}
	//mlx_put_image_to_window(data->mlx, data->win, data->img_screen.img, 0, 0);
}