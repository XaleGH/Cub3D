#include "../inc/cub3d.h"

int	key_press(int keycode, t_data *data)
{
	(void)data;
	if (keycode == RL)
		printf("RL\n");
	if (keycode == RR)
		printf("RR\n");
	if (keycode == FWD)
		printf("FWD\n");
	if (keycode == BACK)
		printf("BACK\n");
	if (keycode == LEFT)
		printf("LEFT\n");
	if (keycode == RIGHT)
		printf("RIGHT\n");
	return (0);
}

int handle_events(int keycode, t_data *data)
{
	if (keycode == ECHAP)
		handle_close(data);
	return (0);
}

int	handle_close(t_data *data)
{
	free_array(data->map);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	//mlx_loop_end(data->mlx);
	exit(0);
	return (1);
}