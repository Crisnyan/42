/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanica- <cmanica-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:12:45 by cmanica-          #+#    #+#             */
/*   Updated: 2024/03/05 17:06:25 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



t_pos	**points(float **mat, int lines, int rows, t_data img)
{
	int		i;
	int		j;
	t_pos	**pos;

	pos = (t_pos **)malloc(sizeof(t_pos *) * lines);
	i = -1;
	while (++i < lines)
	{
		j = -1;
		pos[i] = (t_pos *)malloc(sizeof(t_pos) * rows);
		while (++j < rows)
		{
			pos[i][j].x = j;
			pos[i][j].y = i;
			pos[i][j].z = mat[i][j];
			printf("PUNTO %d, %d\n", i, j);
			printf("POSICION X: %d\n", pos[i][j].x);
			printf("POSICION Y: %d\n", pos[i][j].y);
			printf("POSICION Z: %.0f\n", pos[i][j].z);
		}
		printf("\n");
	}
	return (free(mat), pos);
	//haz free de los pointers dentro de la matriz
}

void	pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	display_points(t_data img, t_pos **pos)
{
	t_data	img;
	t_data *ptr;

	ptr->win = 
	img = (1920, 1080);
	while (img
}

int	main(int argc, char **argv)
{
	int		num[3];
	float	**mat;
	t_pos	**pos;

	if (argc == 2)
	{
		num[LINES] = get_lines(argv[1]);
		num[ROWS] = get_rows(argv[1]);
		num[FD] = open(argv[1], O_RDONLY);
		mat = parser(num[FD], num[LINES], num[ROWS]);
		pos = points(mat, num[LINES], num[ROWS], img);
		display_points(img, points);
	}
}
