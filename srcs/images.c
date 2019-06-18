/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:15:15 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/05/14 12:19:00 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	image_set_pixel(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	*(int*)(image->ptr + ((x + y * WIN_WIDTH) * image->bpp)) = color;
}

void	clear_image(t_image *image)
{
	ft_bzero(image->ptr, WIN_WIDTH * WIN_HEIGHT * image->bpp);
}

t_image	*del_image(t_mlx *mlx, t_image *image)
{
	if (image != NULL)
	{
		if (image->image)
			mlx_destroy_image(mlx->mlx, image->image);
		ft_memdel((void**)&image);
	}
	return (NULL);
}

t_image	*new_image(t_mlx *mlx)
{
	t_image *image;

	if (!(image = ft_memalloc(sizeof(t_image))))
		return (NULL);
	if (!(image->image = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT)))
		return (del_image(mlx, image));
	image->ptr = mlx_get_data_addr(image->image, &image->bpp, &image->stride,
			&image->endian);
	image->bpp /= 8;
	return (image);
}
