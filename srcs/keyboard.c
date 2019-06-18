/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:15:26 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/05/14 12:21:29 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		hook_keypress(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == 53)
		exit(0);
	if (key == 69)
	{
		mlx->cam->scale += 4.2f;
		mlx_clear_window(mlx, mlx->window);
		render(mlx);
	}
	else if (key == 78)
	{
		mlx->cam->scale -= 4.2f;
		if (mlx->cam->scale < 1)
			mlx->cam->scale = 1;
		mlx_clear_window(mlx, mlx->window);
		render(mlx);
	}
	else if (key == 49)
		change_color(mlx);
	mlx->button = key;
	return (0);
}

int		hook_keyrelease(int key, t_mlx *mlx)
{
	(void)mlx;
	(void)key;
	mlx->button = 0;
	return (0);
}
