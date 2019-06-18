/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:16:18 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/05/14 12:22:12 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	(void)button;
	(void)x;
	if (y < 0)
		return (0);
	mlx->mouse->isclick = 1;
	return (0);
}

int	hook_mouseup(int button, int x, int y, t_mlx *mlx)
{
	(void)button;
	(void)x;
	(void)y;
	mlx->mouse->isclick = 0;
	return (0);
}

int	hook_mousemove(int x, int y, t_mlx *mlx)
{
	mlx->mouse->lastx = mlx->mouse->x;
	mlx->mouse->lasty = mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	if (mlx->mouse->isclick && !mlx->button)
	{
		mlx->cam->x += (mlx->mouse->lasty - y) / 420.0f;
		mlx->cam->y -= (mlx->mouse->lastx - x) / 420.0f;
	}
	else if (mlx->mouse->isclick && mlx->button == 256)
	{
		mlx->cam->offsetx += (x - mlx->mouse->lastx);
		mlx->cam->offsety += (y - mlx->mouse->lasty);
	}
	if (mlx->mouse->isclick)
	{
		mlx_clear_window(mlx, mlx->window);
		render(mlx);
	}
	return (0);
}
