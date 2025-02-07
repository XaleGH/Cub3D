/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:00:02 by asaux             #+#    #+#             */
/*   Updated: 2025/02/07 15:01:09 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	my_mlx_pixel_put(t_img *img_screen, int x, int y, int color)
{
	char	*dst;

	dst = img_screen->addr + (y * img_screen->line_length + x
			* (img_screen->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
