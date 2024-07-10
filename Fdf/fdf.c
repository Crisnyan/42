/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanica- <cmanica-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:12:45 by cmanica-          #+#    #+#             */
/*   Updated: 2024/03/08 20:00:58 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mat	*points(int **posz, int lines, int rows)
{
	int		i;
	int		j;
	int		k;
	t_mat	*pos;

	i = -1;
	k = 0;
	pos = (t_mat *)malloc(sizeof(t_mat) * lines * rows);
	while (++i < lines)
	{
		j = -1;
		while (++j < rows)
		{
			pos[k] = cmat(cvec(j - rows / 2, 0, 0), cvec(0, -i + lines / 2, 0), cvec(0, 0, posz[i][j]));
			//printf("PUNTO %d, %d\n", i, j);
			////printmat(pos[k]);
//			//printf(" X1: %d", pos[k]->c1.x);
//			//printf(" Y1: %d", pos[k]->c1.y);
//			//printf(" Z1: %d\n", pos[k]->c1.z);
//			//printf(" X2: %d", pos[k]->c2.x);
//			//printf(" Y2: %d", pos[k]->c2.y);
//			//printf(" Z2: %d\n", pos[k]->c2.z);
//			//printf(" X3: %d", pos[k]->c3.x);
//			//printf(" Y3: %d", pos[k]->c3.y);
//			//printf(" Z3: %d\n", pos[k]->c3.z);
			k++;
		}
		//printf("\n");
	}
	return (pos);
}

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bit_pix / 8));
	*(unsigned int*)dst = color;
}

void	display_points(t_mat *pos, int lines, int rows)
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
	{
//		//printf("Pintando %d: x= %.2f | y = %.2f", i + 1, pos[i].c1.x + pos[i].c2.x + WIDTH / 2, pos[i].c1.y + pos[i].c2.y + HEIGHT / 2);
		if (pos[i].c1.x + pos[i].c2.x + pos[i].c3.x + WIDTH / 2 >= WIDTH || pos[i].c1.x + pos[i].c2.x + pos[i].c3.x + WIDTH / 2 < 0)
			continue ;
		if (-(pos[i].c1.y + pos[i].c2.y + pos[i].c3.y) + HEIGHT / 2 >= HEIGHT || -(pos[i].c1.y + pos[i].c2.y + pos[i].c3.y)+ HEIGHT / 2 < 0)
			continue ;
	//	if (i % 2)
			pixel_put(&img, pos[i].c1.x + pos[i].c2.x + pos[i].c3.x + WIDTH / 2, -(pos[i].c1.y + pos[i].c2.y + pos[i].c3.y) + HEIGHT / 2, 0x0000FF00);
	//	else
	//		pixel_put(&img, pos[i].c1.x + pos[i].c2.x + /*pos[i].c3.x +*/ WIDTH / 2, -(pos[i].c1.y + pos[i].c2.y /*+ pos[i].c3.yi*/) + HEIGHT / 2, 0x0000FF00);
		//pixel_put(&img, pos[i].c1.x + pos[i].c2.x + WIDTH / 2 - lines * 8, pos[i].c1.y + pos[i].c2.y + HEIGHT / 2 - rows * 8, 0x00FFFFFF);
		//pixel_put(&img, pos[i].c1.x + pos[i].c2.x + WIDTH / 2 - lines * 4, pos[i].c1.y + pos[i].c2.y + HEIGHT / 2 - rows * 4, 0x00FFFFFF);
	}
	pixel_put(&img, WIDTH / 2, HEIGHT / 2, 0x00FF0000);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
}

t_mat	mat_mul(t_mat m1, t_mat m2)
{
	t_mat	res;

	//printf("INICIO DE OPERACION\n");
	////printmat(m1);
	////printmat(m2);
	res.c1.x = m1.c1.x * m2.c1.x + m1.c1.y * m2.c2.x + m1.c1.z * m2.c3.x;  
	res.c1.y = m1.c1.x * m2.c1.y + m1.c1.y * m2.c2.y + m1.c1.z * m2.c3.y;  
	res.c1.z = m1.c1.x * m2.c1.z + m1.c1.y * m2.c2.z + m1.c1.z * m2.c3.z;  
	res.c2.x = m1.c2.x * m2.c1.x + m1.c2.y * m2.c2.x + m1.c2.z * m2.c3.x;  
	res.c2.y = m1.c2.x * m2.c1.y + m1.c2.y * m2.c2.y + m1.c2.z * m2.c3.y;  
	res.c2.z = m1.c2.x * m2.c1.z + m1.c2.y * m2.c2.z + m1.c2.z * m2.c3.z;  
	res.c3.x = m1.c3.x * m2.c1.x + m1.c3.y * m2.c2.x + m1.c3.z * m2.c3.x;  
	res.c3.y = m1.c3.x * m2.c1.y + m1.c3.y * m2.c2.y + m1.c3.z * m2.c3.y;  
	res.c3.z = m1.c3.x * m2.c1.z + m1.c3.y * m2.c2.z + m1.c3.z * m2.c3.z;  
	////printmat(res);
	//printf("FINAL DE OPERACION\n");
	return (res);
}
int	main(int argc, char **argv)
{
	int		num[3];
	int		**mat;
	t_mat	*pos;
	t_mat	id;
	t_mat	angx;
	t_mat	angy;
	t_mat	strch;
	int		i;

	//printf("ANGLE: %.2f", ANGLE);
	if (argc != 2)
		return (0);
	id = cmat(cvec(3, 0, 0), cvec(0, 3, 0), cvec(0, 0, 3));
	strch = cmat(cvec(1, 0, 0), cvec(tan(ANGLE), 1, 0), cvec(0, 0, 1));
	angy = cmat(cvec(cos(ANGLE), 0, sin(ANGLE)), cvec(0, 1, 0), cvec(-sin(ANGLE), 0, cos(ANGLE)));
	angx = cmat(cvec(1, 0, 0), cvec(0, -cos(ANGLE), -sin(ANGLE)), cvec(0, -sin(ANGLE), cos(ANGLE)));
//	ang = cmat(cvec(cos(ANGLE), sin(ANGLE), 0), cvec(-sin(ANGLE), cos(ANGLE),  0), cvec(0, 0, 1));
	num[LINES] = get_lines(argv[1]);
	num[ROWS] = get_rows(argv[1]);
	num[FD] = open(argv[1], O_RDONLY);
	//printf("ROWS: %d\n", num[ROWS]);
	//printf("LINES: %d\n", num[LINES]);
	mat = parser(num[FD], num[LINES], num[ROWS]);
	pos = points(mat, num[LINES], num[ROWS]);
	i = -1;
	while (++i < num[ROWS] * num[LINES])
	{
		//printf("Escalar\n");
		*(pos + i) = mat_mul(*(pos + i), id);
//		i++;
//		if (i >= num[ROWS] * num[LINES])
//			break ;
		//printf("Cizallar x\n");
	//	if (i % 2)
	//		*(pos + i) = mat_mul(*(pos + i), strch);
		//printf("Rotar\n");
	//	if (!(i % 2))
			*(pos + i) = mat_mul(*(pos + i), angx);
			*(pos + i) = mat_mul(*(pos + i), angy);
	}
	//printf("ANGLE: %.2f", ANGLE);
	display_points(pos, num[LINES], num[ROWS]);
}
