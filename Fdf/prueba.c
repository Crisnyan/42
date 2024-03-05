/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanica- <cmanica-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:09:07 by cmanica-          #+#    #+#             */ /*   Updated: 2024/03/05 15:09:07 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		linelen;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->linelen + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	t_data	img;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "fdf");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img,  &img.bpp, &img.linelen, &img.endian);
	my_mlx_pixel_put(&img, 0, 0, 0x00FFFFFF);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
}
