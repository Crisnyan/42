/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanica- <cmanica-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:51:40 by cmanica-          #+#    #+#             */
/*   Updated: 2024/03/08 19:53:53 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	cvec(float x, float y, float z)
{
	t_vec3 vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}
	
t_mat	cmat(t_vec3 vec1, t_vec3 vec2, t_vec3 vec3)
{
	t_mat	mat;

	mat.c1.x = vec1.x;
	mat.c1.y = vec1.y;
	mat.c1.z = vec1.z;
	mat.c2.x = vec2.x;
	mat.c2.y = vec2.y;
	mat.c2.z = vec2.z;
	mat.c3.x = vec3.x;
	mat.c3.y = vec3.y;
	mat.c3.z = vec3.z;
	return (mat);
}

int	get_lines(char	*file_name)
{
	int		lines;
	int		fd;
	char	*str;

	fd = open(file_name, O_RDONLY);
	str = get_next_line(fd);
	lines = 0;
	while (str != 0)
	{
		lines++;
		str = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

int	get_rows(char	*file_name)
{
	int		rows;
	int		fd;
	char	**strmat;
	char	*str;

	fd = open(file_name, O_RDONLY);
	strmat = ft_split(get_next_line(fd), ' ');
	rows = 0;
	while (strmat[rows])
		rows++;
	str = get_next_line(fd);
	while (str)
		str = get_next_line(fd);
	close(fd);
	return (rows);
}

int	**parser(int fd, int lines, int rows)
{
	char	***strmat;
	int		i;
	int		j;
	int	**posz;

	i = -1;
	strmat = malloc(sizeof(char**) * (lines + 1));
	posz = malloc(sizeof(int *) * (lines));
	while (++i < lines)
		strmat[i] = ft_split(get_next_line(fd), ' ');
	strmat[i + 1] = NULL;
	i = -1;
	while (++i < lines)
	{
		j = -1;
		posz[i] = malloc(sizeof(int) * rows);
		while (++j < rows)
			posz[i][j] = ft_atoi(strmat[i][j]); }
	close(fd);
	return (posz);
}

void	printmat(t_mat mat)
{
	printf(" X1: %.2f", mat.c1.x);
	printf(" Y1: %.2f", mat.c1.y);
	printf(" Z1: %.2f\n", mat.c1.z);
	printf(" X2: %.2f", mat.c2.x);
	printf(" Y2: %.2f", mat.c2.y);
	printf(" Z2: %.2f\n", mat.c2.z);
	printf(" X3: %.2f", mat.c3.x);
	printf(" Y3: %.2f", mat.c3.y);
	printf(" Z3: %.2f\n", mat.c3.z);
	printf("\n");
}
//
//void	center_mat(t_mat *mat, int lines, int rows)
//{
//	lines = 0;
//	rows = 0;
//
//	mat->c1.x = mat->c1.x -  lines / 2;
//	mat->c2.y = mat->c1.y - rows / 2;
//	mat->c3.z = mat->c3.z;
//}
