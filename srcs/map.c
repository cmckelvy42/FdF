/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:15:36 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/05/14 12:16:14 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		project_point(t_point p, t_mlx *mlx)
{
	p.x -= (double)(mlx->map->width - 1) / 2.0f;
	p.y -= (double)(mlx->map->height - 1) / 2.0f;
	p.z -= (double)(mlx->map->depth_min + mlx->map->depth_max) / 2.0f;
	p = rotate(p, mlx->cam);
	p.x *= mlx->cam->scale;
	p.y *= mlx->cam->scale;
	p.x += mlx->cam->offsetx;
	p.y += mlx->cam->offsety;
	return (p);
}

t_point		find_point(t_map *map, int x, int y)
{
	return (*map->points[y * map->width + x]);
}

t_point		*get_point(int x, int y, char *str)
{
	t_point	*point;

	point = ft_memalloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = ft_atoi(str);
	point->color = 0xFFFFFF;
	return (point);
}

t_map		*get_map(int width, int height)
{
	t_map	*map;

	map = ft_memalloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->width = width;
	map->height = height;
	map->depth_max = 0;
	map->depth_min = 0;
	map->points = ft_memalloc(sizeof(t_point*) * width * height + 1);
	if (map->points == NULL)
	{
		ft_memdel((void**)&map);
		return (NULL);
	}
	map->points[width * height] = NULL;
	return (map);
}
