#ifndef CUB3D_H
# define CUB3D_H

/* Library */

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>

//# define BUFFER_SIZE 42
# define PI 			3.14159
# define FOV			60
# define TILE_SIZE 		64
# define SCR_WIDTH 		1900
# define SCR_HEIGHT 	1000
# define ECHAP			65307
# define RL				65361
# define RR				65363
# define BACK			115
# define RIGHT			100
# define FWD			119
# define LEFT			97
# define BUFFER_DIFF    0.008
//azerty :
//# define FWD		122
//# define LEFT			113

/* Structure */

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_texture
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		 line_length;
	int		endian;
	int		height;
	int		width;
	char	*path;
}	t_texture;

typedef struct s_ray
{
	double	r_distance;
	double	r_angle;
	double	horiz_x;
	double	horiz_y;
	double	vert_x;
	double	vert_y;
	int		flag;
}	t_ray;

typedef struct s_player
{
	int		map_x;
	int		map_y;
	int		p_x;
	int		p_y;
	float	fov_rad;
	float	p_speed;
	double	p_angle;
}	t_player;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_img			img_screen;
	char			**map;
	int				nb_column;
	int				nb_row;
	int				p_count;
	char			*cc;
	char			*cf;
	int				count_line;
	int				valid_map;
	double			wall_height;
    double			delta_angle;
	int				text_x;
	int				text_y;
	unsigned int	color;
	int				wall[4][TILE_SIZE * TILE_SIZE];
	unsigned long	floor_color;
	unsigned long	ceiling_color;

	t_player		player;
	t_ray			ray;
	t_texture		texture[4];



}		t_data;

/* Fonctions */

/* parsing/parsing_check_file.c */
int		check_exten(char *av);
void	line_cardinal(char *line, t_data *data, int flag);
void	check_line(char *line, t_data *data);
void	check_char_map(t_data *data);
void	check_player(t_data *data);

/* parsing/parsing_color.c */
void	check_color(t_data *data);
void	clean_color_cc(t_data *data);
void	clean_color_cf(t_data *data);
void	check_value_color(t_data *data);
void	line_color(char *line, t_data *data, int flag);

/* parsing/parsing_map_closed.c */
int		check_in_map(char **map_cpy, int x, int y, t_data *data);
void	check_angle(char **map_cpy, int y, int x, t_data *data);
void	is_closed(char **map_cpy, int y, int x, t_data *data);
void	check_wall(t_data *data);

/* parsing/parsing.c */
void    init_cell_floor_color(t_data *data);
void	init_map_data(t_data *data);
void	read_map(int file, t_data *data);
void	read_option(char **av, t_data *data);
int		parsing(char **av, t_data *data);

/* player/input.c */
int 	key_press(int keycode, t_data *data);
int		handle_events(int keycode, t_data *data);
int 	handle_close(t_data *data);

/* player/moves.c */
void	rotate(t_data *data, int direction);
void	forward_or_back(t_data *data, int dir);
void	left_or_right(t_data *data, int dir);

/* raycasting/draw_wall.c */
int		get_texture(t_data *data);
void	get_text_x(t_data *data, int text_nb);
void	draw_wall(t_data *data, int top_pix, int bottom_pix, int ray);
void	display_wall(t_data *data, int ray);
void	draw_floor_ceiling(t_data *data, int ray, int bottom_pix, int top_pix);

/* raycasting/raycasting_utils.c */
double	normalize_angle(double angle);
double	get_first_step(t_data *data, char dir);
double	get_inter(t_data *data, char dir);

/* raycasting/raycasting.c */
int		hit_wall(t_data *data, double x, double y, char flag);
double	get_horizontal_distance(t_data *data);
double	get_vertical_distance(t_data *data);
void	get_shorter_distance(t_data *data);
void	raycasting(t_data *data);

/* raycasting/init_texture.c*/
void	init_textures(t_data *data);
char	*get_data_address(t_texture *texture);
void	store_textures_pixels(t_data *data, int i);
void	*convert_img(t_data *data, char *path, int i);
void	init_texture_data(t_data *data);

/* utils/ft_error.c */
void	ft_error(int flag);
void	ft_error_data(t_data *data, int flag);
void	free_char_option(t_data *data);
void	free_mlx(t_data *data);

/* utils/ft_utils.c */
void	free_array(char **array);
int		rgb_to_hex(char *rgb_str);
void	free_paths(t_data *data);

/* utils/rendering_utils.c */
void	my_mlx_pixel_put(t_img *img_screen, int x, int y, int color);

/* main.c */

#endif