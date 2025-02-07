#include "../../inc/cub3d.h"

int	check_exten(char *av)
{
	int		i;
	int		j;
	char	*ext;

	ext = ".cub";
	i = ft_strlen(av) - 1;
	j = 3;
	while (av[i] != '.')
	{
		if (av[i] != ext[j])
			ft_error(1);
		i--;
		j--;
	}
	return (0);
}

void	line_cardinal(char *line, t_data *data, int flag)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	i += 2;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	j = i;
	while (line[i] != ' ' && (line[i] <= 9 || line[i] >= 13))
		i++;
	if (line[j] != '.' && line[j + 1] != '/')
		ft_error_data(data, 0);
	if (flag == 1)
		data->texture[0].path = ft_strndup_gnl(line + j, (i - j));
	if (flag == 2)
		data->texture[1].path = ft_strndup_gnl(line + j, (i - j));
	if (flag == 3)
		data->texture[2].path = ft_strndup_gnl(line + j, (i - j));
	if (flag == 4)
		data->texture[3].path = ft_strndup_gnl(line + j, (i - j));
	data->count_line += 1;
}

void	check_line(char *line, t_data *data)
{
	int	i;

	i = 0;
	if (line[i] == '\n')
		return ;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O' && data->texture[0].path == NULL)
		line_cardinal(line, data, 1);
	else if (line[i] == 'S' && line[i + 1] == 'O' && data->texture[1].path == NULL)
		line_cardinal(line, data, 2);
	else if (line[i] == 'W' && line[i + 1] == 'E' && data->texture[2].path == NULL)
		line_cardinal(line, data, 3);
	else if (line[i] == 'E' && line[i + 1] == 'A' && data->texture[3].path == NULL)
		line_cardinal(line, data, 4);
	else if (line[i] == 'C' && data->cc == NULL)
		line_color(line, data, 1);
	else if (line[i] == 'F' && data->cf == NULL)
		line_color(line, data, 2);
	else
	{
		free(line);
		ft_error_data(data, 1);
	}
}

void    init_p_angle(t_data *data, char dir)
{
	if (dir == 'N')
		data->player.p_angle = 3 * PI / 2;
	if (dir == 'S')
		data->player.p_angle = PI / 2;
	if (dir == 'E')
		data->player.p_angle = 0;
	if (dir == 'W')
		data->player.p_angle = PI;
}

void    init_player(t_data *data, int x, int y)
{
	data->player.map_x = x;
	data->player.map_y = y;
	data->player.p_x = x * TILE_SIZE + TILE_SIZE / 2;
	data->player.p_y = y * TILE_SIZE + TILE_SIZE / 2;
	data->player.p_speed = 10;
	data->player.fov_rad = (FOV * PI / 180);
	init_p_angle(data, data->map[y][x]);
}

void	check_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N'
			|| data->map[y][x] == 'S'
			|| data->map[y][x] == 'E'
			|| data->map[y][x] == 'W')
			{
				init_player(data, x, y);
				data->p_count += 1;
			}
			x++;
		}
		y++;
	}
	if (data->p_count == 0 || data->p_count > 1)
		ft_error_data(data, 7);
}

void	check_char_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == ' '
			|| data->map[y][x] == '1'
			|| data->map[y][x] == '0'
			|| data->map[y][x] == 'N'
			|| data->map[y][x] == 'S'
			|| data->map[y][x] == 'E'
			|| data->map[y][x] == 'W')
				x++;
			else
				ft_error_data(data, 4);
		}
		y++;
	}
	data->nb_row = y;
}
