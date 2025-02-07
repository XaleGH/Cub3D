/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:59:27 by thsion            #+#    #+#             */
/*   Updated: 2025/02/07 15:00:36 by thsion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// 0 = NO ; 1 = SO ; 2 = WE ; 3 = EA

int	get_texture(t_data *data)
{
	data->ray.r_angle = normalize_angle(data->ray.r_angle);
	if (data->ray.flag == 0)
	{
		if (data->ray.r_angle > PI / 2 && data->ray.r_angle < 3 * (PI / 2))
			return (2);
		else
			return (3);
	}
	else
	{
		if (data->ray.r_angle > 0 && data->ray.r_angle < PI)
			return (1);
		else
			return (0);
	}
}

void	get_text_x(t_data *data, int text_nb)
{
	if (data->ray.flag == 1)
	{
		data->text_x = fmodf(data->ray.horiz_x, TILE_SIZE);
		if (text_nb == 1)
			data->text_x = TILE_SIZE - data->text_x;
	}
	else
	{
		data->text_x = fmodf(data->ray.vert_y, TILE_SIZE);
		if (text_nb == 2)
			data->text_x = TILE_SIZE - data->text_x;
	}
}

void	draw_wall(t_data *data, int top_pix, int bottom_pix, int ray)
{
	int		text_nb;
	double	step;
	double	pos_y;

	text_nb = get_texture(data);
	step = TILE_SIZE / data->wall_height;
	pos_y = (top_pix - SCR_HEIGHT / 2 + data->wall_height / 2) * step;
	get_text_x(data, text_nb);
	while (top_pix < bottom_pix)
	{
		data->text_y = pos_y;
		data->color = data->wall[text_nb][TILE_SIZE
			* data->text_y + data->text_x];
		pos_y += step;
		if (data->ray.flag == 0)
			data->color = (data->color >> 1) & 8355711;
		my_mlx_pixel_put(&data->img_screen, ray, top_pix, data->color);
		top_pix++;
	}
}

void	display_wall(t_data *data, int ray)
{
	double	bottom_pix;
	double	top_pix;

	data->ray.r_distance *= cos(normalize_angle(data->ray.r_angle
				- data->player.p_angle));
	data->wall_height = (TILE_SIZE / data->ray.r_distance)
		* ((SCR_WIDTH / 2) / tan(data->player.fov_rad / 2));
	bottom_pix = (SCR_HEIGHT / 2) + (data->wall_height / 2);
	top_pix = (SCR_HEIGHT / 2) - (data->wall_height / 2);
	if (bottom_pix > SCR_HEIGHT)
		bottom_pix = SCR_HEIGHT;
	if (top_pix < 0)
		top_pix = 0;
	draw_wall(data, top_pix, bottom_pix, ray);
	draw_floor_ceiling(data, ray, bottom_pix, top_pix);
}

void	draw_floor_ceiling(t_data *data, int ray, int bottom_pix, int top_pix)
{
	int	i;

	i = bottom_pix;
	while (i < SCR_HEIGHT)
	{
		my_mlx_pixel_put(&data->img_screen, ray, i, data->floor_color);
		i++;
	}
	i = 0;
	while (i < top_pix)
	{
		my_mlx_pixel_put(&data->img_screen, ray, i, data->ceiling_color);
		i++;
	}
}
