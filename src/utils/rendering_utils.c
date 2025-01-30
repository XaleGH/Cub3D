#include "../../inc/cub3d.h"

void	my_mlx_pixel_put(t_img *img_screen, int x, int y, int color)
{
	char	*dst;

	dst = img_screen->addr + (y * img_screen->line_length + x * (img_screen->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
