/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanica- <cmanica-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:12:45 by cmanica-          #+#    #+#             */
/*   Updated: 2024/03/06 17:54:00 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mat	**points(float **z_pos, int lines, int rows)
{
	int		i;
	int		j;
	int		k;
	t_mat	**pos;

	i = -1;
	k = 0;
	pos = (t_mat **)malloc(sizeof(t_mat *) * lines * rows);
	while (++i < lines)
	{
		j = -1;
		while (++j < rows)
		{
			pos[k] = mat_create(j, i, z_pos[i][j]);
//			pos[k]->row1.x = j;
//		   	pos[k]->row2.y = i;
//		   	pos[k]->row3.z = z_pos[i][j];
			printf("PUNTO %d, %d\n", i, j);
			printf(" X1: %d", pos[k]->row1.x);
			printf(" Y1: %d", pos[k]->row1.y);
			printf(" Z1: %d\n", pos[k]->row1.z);
			printf(" X2: %d", pos[k]->row2.x);
			printf(" Y2: %d", pos[k]->row2.y);
			printf(" Z2: %d\n", pos[k]->row2.z);
			printf(" X3: %d", pos[k]->row3.x);
			printf(" Y3: %d", pos[k]->row3.y);
			printf(" Z3: %d\n", pos[k]->row3.z);
			k++;
		}
		printf("\n");
	}
	return (pos);
}

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bit_pix / 8));
	*(unsigned int*)dst = color;
}

void	display_points(t_mat **pos, int lines, int rows)
{
	void	*mlx;
	t_data	img;
	void	*win;
	int		i;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "fdf");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img,  &img.bit_pix, &img.len, &img.endian);
	i = -1;
	while (++i < lines * rows)
		pixel_put(&img, pos[i]->row1.x, pos[i]->row2.y, 0x00FFFFFF);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
}
int	main(int argc, char **argv)
{
	int		num[3];
	float	**mat;
	t_mat	**pos;

	if (argc == 2)
	{
		num[LINES] = get_lines(argv[1]);
		num[ROWS] = get_rows(argv[1]);
		num[FD] = open(argv[1], O_RDONLY);
		printf("ROWS: %d\n", num[ROWS]);
		printf("LINES: %d\n", num[LINES]);
		mat = parser(num[FD], num[LINES], num[ROWS]);
		printf("pasa");
		pos = points(mat, num[LINES], num[ROWS]);
		display_points(pos, num[LINES], num[ROWS]);
	}
}
