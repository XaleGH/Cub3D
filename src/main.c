#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_error(0);
	check_exten(av[1]);
	parsing(av, &data);
	initialization(&data);
	if (data.map[0] != NULL)
		free_array(data.map);
	free_char_option(&data);
	return (0);
}

void	initialization(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SCR_WIDTH, SCR_HEIGHT, "Cub3D");
	data->img_screen.img = mlx_new_image(data->mlx, SCR_WIDTH, SCR_HEIGHT);
	data->img_screen.addr = mlx_get_data_addr(data->img_screen.img, &data->img_screen.bits_per_pixel,
			&data->img_screen.line_length, &data->img_screen.endian);
	// KICK IN DU RAYCASTING
	mlx_put_image_to_window(data->mlx, data->win, data->img_screen.img, 0, 0);
	// IMPLEMENTER LES HOOKS
    printf("check in init : %s\n", data->map[0]);
	mlx_hook(data->win, 02, 1L << 0, &key_press, data);
	mlx_key_hook(data->win, &handle_events, data);
	mlx_hook(data->win, 17, 0, &handle_close, data);
	mlx_loop(data->mlx);
}
