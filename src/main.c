#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = 0;
	if (ac != 2)
		ft_error(0);
	check_exten(av[1]);
	//printf("allo\n");
	parsing(av, &data);
	initialization(&data);

	printf("NO : %s\n", data.no);
	printf("SO : %s\n", data.so);
	printf("WE : %s\n", data.we);
	printf("EA : %s\n", data.ea);
	printf("C : %s\n", data.cc);
	printf("F : %s\n", data.cf);
	while (i < 14)
	{
		printf("ligne %d : %s\n", i, data.map[i]);
		i++;
	}


	if (data.map[0] != NULL)
		free_array(data.map);
	free_char_option(&data);

	
	return (0);
	//display_map(&data);
	//mlx_key_hook(data.mlx_win, handle_events, &data);
	//mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	//mlx_loop(data.mlx);
}

void	initialization(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SCR_WIDTH, SCR_HEIGHT, "Cub3D");
	data->img = mlx_new_image(data->mlx, SCR_WIDTH, SCR_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
			&data->endian);
	data->width = SCR_WIDTH;
	data->height = SCR_HEIGHT;
	data->offset_x = 0;
	data->width = SCR_WIDTH;
	data->height = SCR_HEIGHT;
	data->offset_y = 0;
	data->av_x = 0;
	data->av_y = 0;

	// KICK IN DU RAYCASTING

	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	
	// IMPLEMENTER LES HOOKS
	
	mlx_hook(data->win, 02, 1L << 0, key_press, &data);
	mlx_key_hook(data->win, handle_events, &data);
	mlx_hook(data->win, 17, 0, handle_close, &data);
	mlx_loop(data->mlx);
}

/* int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = 0;
	if (ac != 2)
		ft_error(0);
	check_exten(av[1]);
	parsing(av, &data);


	printf("NO : %s\n", data.no);
	printf("SO : %s\n", data.so);
	printf("WE : %s\n", data.we);
	printf("EA : %s\n", data.ea);
	printf("C : %s\n", data.cc);
	printf("F : %s\n", data.cf);
	while (i < 14)
	{
		printf("ligne %d : %s\n", i, data.map[i]);
		i++;
	}


	if (data.map[0] != NULL)
		free_array(data.map);
	free_char_option(&data);

	
	return (0);
	//display_map(&data);
	//mlx_key_hook(data.mlx_win, handle_events, &data);
	//mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	//mlx_loop(data.mlx);
} */