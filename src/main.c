#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_error(0);
	check_exten(av[1]);
	parsing(av, &data);
    init_cell_floor_color(&data);
    init_textures(&data);
    raycasting(&data);
	mlx_hook(data.win, 02, 1L << 0, &key_press, &data);
	mlx_key_hook(data.win, &handle_events, &data);
	mlx_hook(data.win, 17, 0, &handle_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
