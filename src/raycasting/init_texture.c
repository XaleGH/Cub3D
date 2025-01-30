#include "../../inc/cub3d.h"

void	init_texture_data(t_data *data)
{
	int	i;

	i = 0;
	while(i < 4)
	{
		data->texture[i].width = TILE_SIZE;
		data->texture[i].height = TILE_SIZE;
		i++;
	}
}

void	*convert_img(t_data *data, char *path, int i)
{
	void	*img;
	char	*txt;

	img = mlx_xpm_file_to_image(data->mlx, path, &(data->texture[i].width), &(data->texture[i].width));
	if (!img)
	{
		if (i == 0)
			txt = "NO";
		else if (i == 1)
			txt = "SO";
		else if (i == 1)
			txt = "WE";
		else if (i == 1)
			txt = "EA";
		printf("error\npath to texture %s is invalid\n", txt);
		free_array(data->map);
		free_char_option(data);
		free_mlx(data);
		exit(1);
	}
	return(img);
}

void	store_textures_pixels(t_data *data, int i)
{
	int	x;
	int	y;
	int	text_i;

	y = 0;
	while (y < data->texture[i].height)
	{
		x = 0;
		while (x < data->texture[i].width)
		{
			text_i = data->texture[i].height * y + x;
			data->wall[i][text_i] = data->texture[i].addr[text_i];
			x++;
		}
		y++;
	}
}

char	*get_data_address(t_texture *texture)
{
	char	*address;

	address = mlx_get_data_addr(texture->img, &(texture->bits_per_pixel), &(texture->line_length), &(texture->endian));
	return (address);
}

void	init_textures(t_data *data)
{
	int	i;

	i = 0;
	init_texture_data(data);
	while(i < 4)
	{
		data->texture[i].img = convert_img(data, data->texture[i].path, i);
		if (!data->texture[i].img)
			printf("failed to load img\n");
		data->texture[i].addr = (int *)get_data_address(&(data->texture[i]));
		if (!data->texture[i].addr)
			printf("failed to load texture address\n");
		store_textures_pixels(data, i);
		mlx_destroy_image(data->mlx, data->texture[i].img);
		i++;
	}
}