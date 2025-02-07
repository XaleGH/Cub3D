/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:54:20 by thsion            #+#    #+#             */
/*   Updated: 2025/02/07 14:55:32 by thsion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == RL)
		rotate(data, 1);
	if (keycode == RR)
		rotate(data, -1);
	if (keycode == FWD && check_pos(data))
		forward_or_back(data, 1);
	if (keycode == BACK)
		forward_or_back(data, -1);
	if (keycode == LEFT)
		left_or_right(data, -1);
	if (keycode == RIGHT)
		left_or_right(data, 1);
	return (0);
}

bool	check_pos(t_data *data)
{
	if ((int)data->ray.r_distance < 10)
		return (false);
	return (true);
}

int	handle_events(int keycode, t_data *data)
{
	if (keycode == ECHAP)
		handle_close(data);
	return (0);
}

int	handle_close(t_data *data)
{
	free_array(data->map);
	free_char_option(data);
	mlx_destroy_image(data->mlx, data->img_screen.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	mlx_loop_end(data->mlx);
	free(data->mlx);
	exit(0);
	return (1);
}
