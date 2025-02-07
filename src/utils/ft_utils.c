/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:59:58 by asaux             #+#    #+#             */
/*   Updated: 2025/02/07 15:00:12 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

int	rgb_to_hex(char *rgb_str)
{
	int		r;
	int		g;
	int		b;
	char	**rgb;
	int		color;

	rgb = ft_split(rgb_str, ',');
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_array(rgb);
	color = (r << 16) | (g << 8) | b;
	return (color);
}

void	free_paths(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->p_count)
	{
		free(data->texture[i].path);
		i++;
	}
	return ;
}
