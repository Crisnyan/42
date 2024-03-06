/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanica- <cmanica-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:12:45 by cmanica-          #+#    #+#             */
/*   Updated: 2024/03/06 19:18:41 by cmanica-         ###   ########.fr       */
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
			printf("PUNTO %d, %d\n", i, j);
			printf(" X1: %d", pos[k]->c1.x);
			printf(" Y1: %d", pos[k]->c1.y);
			printf(" Z1: %d\n", pos[k]->c1.z);
			printf(" X2: %d", pos[k]->c2.x);
			printf(" Y2: %d", pos[k]->c2.y);
			printf(" Z2: %d\n", pos[k]->c2.z);
			printf(" X3: %d", pos[k]->c3.x);
			printf(" Y3: %d", pos[k]->c3.y);
			printf(" Z3: %d\n", pos[k]->c3.z);
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
		pixel_put(&img, pos[i]->c1.x, pos[i]->c2.y, 0x00FFFFFF);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
}

t_mat	mat_mul(t_mat m1, t_mat m2)
{
	t_mat	res;

	res.c1.x = m1.c1.x * m2.c1.x + m1.c1.y * m2.c2.x + m1.c1.z * m2.c3.x;  
	res.c1.y = m1.c1.x * m2.c1.y + m1.c1.y * m2.c2.y + m1.c1.z * m2.c3.y;  
	res.c1.z = m1.c1.x * m2.c1.z + m1.c1.y * m2.c2.z + m1.c1.z * m2.c3.z;  
	res.c2.x = m1.c2.x * m2.c1.x + m1.c2.y * m2.c2.x + m1.c2.z * m2.c3.x;  
	res.c2.y = m1.c2.x * m2.c1.y + m1.c2.y * m2.c2.y + m1.c2.z * m2.c3.y;  
	res.c2.z = m1.c2.x * m2.c1.z + m1.c2.y * m2.c2.z + m1.c2.z * m2.c3.z;  
	res.c3.x = m1.c3.x * m2.c1.x + m1.c3.y * m2.c2.x + m1.c3.z * m2.c3.x;  
	res.c3.y = m1.c3.x * m2.c1.y + m1.c3.y * m2.c2.y + m1.c3.z * m2.c3.y;  
	res.c3.z = m1.c3.x * m2.c1.z + m1.c3.y * m2.c2.z + m1.c3.z * m2.c3.z;  
	return (res);
}
int	main(int argc, char **argv)
{
	int		num[3];
	float	**mat;
	t_mat	**pos;
	t_mat	*id;

	if (argc != 2)
		return (0);
	id = mat_create(1,1,1);	
	num[LINES] = get_lines(argv[1]);
	num[ROWS] = get_rows(argv[1]);
	num[FD] = open(argv[1], O_RDONLY);
	printf("ROWS: %d\n", num[ROWS]);
	printf("LINES: %d\n", num[LINES]);
	mat = parser(num[FD], num[LINES], num[ROWS]);
	pos = points(mat, num[LINES], num[ROWS]);
	*(*pos + 2) = mat_mul(*(*pos + 2), *id);
			printf(" X1: %d", (*pos + 2)->c1.x);
			printf(" Y1: %d", (*pos + 2)->c1.y);
			printf(" Z1: %d\n", (*pos + 2)->c1.z);
			printf(" X2: %d", (*pos + 2)->c2.x);
			printf(" Y2: %d", (*pos + 2)->c2.y);
			printf(" Z2: %d\n", (*pos + 2)->c2.z);
			printf(" X3: %d", (*pos + 2)->c3.x);
			printf(" Y3: %d", (*pos + 2)->c3.y);
			printf(" Z3: %d\n", (*pos + 2)->c3.z);
	display_points(pos, num[LINES], num[ROWS]);
}
