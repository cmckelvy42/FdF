/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:03:51 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/05/15 12:05:03 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_WIDTH 	1080
# define WIN_HEIGHT	1080
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

typedef struct		s_cam
{
	int			offsetx;
	int			offsety;
	double			x;
	double			y;
	double			scale;
	int			**matrix;
}					t_cam;

typedef struct		s_mouse
{
	int			isclick;
	int			lastx;
	int			lasty;
	int			x;
	int			y;
}					t_mouse;

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_point;

typedef struct	s_map
{
	int			width;
	int			height;
	int			depth_min;
	int			depth_max;
	t_point		**points;
}				t_map;

typedef struct 	s_image
{
	void	*image;
	char	*ptr;
	int		bpp;
	int		stride;
	int		endian;	
}				t_image;

typedef struct 	s_mlx
{
	void	*mlx;
	void	*window;
	t_image	*image;
	t_map	*map;
	t_cam	*cam;
	t_mouse	*mouse;
	int		button;
}				t_mlx;

typedef struct 	s_line
{
	double			dx;
	double			dy;
	double			sx;
	double			sy;
	int			err;
	int			err2;
	t_point	start;
	t_point	end;
}				t_line;

void		plotline(t_mlx *mlx, t_point p1, t_point p2);
int     	read_file(int fd, t_map **map);
t_map       *get_map(int width, int height);
t_point     find_point(t_map *map, int x, int y);
t_point    	*get_point(int x, int y, char *str);
t_point		project_point(t_point p, t_mlx *mlx);
void		render(t_mlx *mlx);
t_point 	rotate(t_point p, t_cam *r);
t_image 	*del_image(t_mlx *mlx, t_image *image);
void		image_set_pixel(t_image *image, int x, int y, int color);
void    	clear_image(t_image *image);
t_image		*new_image(t_mlx *mlx);
int			hook_keypress(int key, t_mlx *mlx);
int			hook_keyrelease(int key, t_mlx *mlx);
int 		hook_mousemove(int x, int y, t_mlx *mlx);
int 		hook_mouseup(int button, int x, int y, t_mlx *mlx);
int 		hook_mousedown(int button, int x, int y, t_mlx *mlx);
void       	change_color(t_mlx *mlx);
void		print_help(t_mlx *mlx);
#endif
