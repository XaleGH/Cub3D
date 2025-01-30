#include "../../inc/cub3d.h"

void	ft_error(int flag)
{
	errno = 1;
	if (flag == 0)
		perror("Error\nInvalid arguments ");
	if (flag == 1)
		perror("Error\nWrong extension, only .cub extension ");
	if (flag == 2)
		perror("Error\nFile can't be opened ");
	if (flag == 3)
		perror("Error\nFile is empty ");
	exit (1);
}

void	ft_error_data(t_data *data, int flag)
{
	errno = 1;
	if (flag == 0)
		perror("Error\nWrong path detected ");
	if (flag == 1)
		perror("Error\nWrong entry in the file ");
	if (flag == 2)
		perror("Error\nWrong color code ");
	if (flag == 3)
		perror("Error\nColor code need between 0 and 255 ");
	if (flag == 4)
		perror("Error\nWrong char in the map ");
	if (flag == 5)
		perror("Error\nMap not close ");
	if (flag == 6)
		perror("Error\nSame path for texture detected ");
	if (flag == 7)
		perror("Error\nOne and only one player needed ");
	if (flag == 8)
		perror("");
	if (data->map != NULL)
		free_array(data->map);
	free_char_option(data);
	exit (1);
}

void	free_char_option(t_data *data)
{
	if (data->texture[0].path != NULL)
		free(data->texture[0].path);
	if (data->texture[1].path != NULL)
		free(data->texture[1].path);
	if (data->texture[2].path != NULL)
		free(data->texture[2].path);
	if (data->texture[3].path != NULL)
		free(data->texture[3].path);
	if (data->cc != NULL)
		free(data->cc);
	if (data->cf != NULL)
		free(data->cf);
}

void	free_mlx(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	return;
}

