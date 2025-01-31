#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;
    int i = 0;

	if (ac != 2)
		ft_error(0);
	check_exten(av[1]);
	/* data.mlx = mlx_init();
	data.win = mlx_new_window(&data.mlx, SCR_WIDTH, SCR_HEIGHT, "Cub3D"); */
	parsing(av, &data);
    init_cell_floor_color(&data);
    while (i < 4)
    {
        printf("%s\n", data.texture[i].path);
        i++;
    }
    init_textures(&data);
    raycasting(&data);
	mlx_hook(data.win, 02, 1L << 0, &key_press, &data);
	mlx_key_hook(data.win, &handle_events, &data);
	mlx_hook(data.win, 17, 0, &handle_close, &data);
	mlx_loop(data.mlx);
	return (0);
}

/* void	initialization(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SCR_WIDTH, SCR_HEIGHT, "Cub3D");
    init_textures(data);
    printf("allo\n");
    raycasting(data);
	mlx_hook(data->win, 02, 1L << 0, &key_press, data);
	mlx_key_hook(data->win, &handle_events, data);
	mlx_hook(data->win, 17, 0, &handle_close, data);
	mlx_loop(data->mlx);
} */
