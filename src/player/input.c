#include "../../inc/cub3d.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == RL)
		rotate(data, 1);
	if (keycode == RR)
		rotate(data, -1);
	if (keycode == FWD)
		forward_or_back(data, 1);
	if (keycode == BACK)
		forward_or_back(data, -1);
	if (keycode == LEFT)
		left_or_right(data, 1);
	if (keycode == RIGHT)
		left_or_right(data, 1);
	return (0);
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
