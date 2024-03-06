/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanica- <cmanica-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:51:40 by cmanica-          #+#    #+#             */
/*   Updated: 2024/03/06 17:34:22 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mat	*mat_create(int x, int y, int z)
{
	t_mat	*mat;

	mat = malloc(sizeof(t_mat));
	if (!mat)
		return (NULL);
	mat->row1.x = x;
	mat->row1.y = 0;
	mat->row1.z = 0;
	mat->row2.x = 0;
	mat->row2.y = y;
	mat->row2.z = 0;
	mat->row3.x = 0;
	mat->row3.y = 0;
	mat->row3.z = z;
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

float **parser(int fd, int lines, int rows)
{
	char	***strmat;
	int		i;
	int		j;
	float	**z_pos;

	i = -1;
	strmat = malloc(sizeof(char**) * (lines + 1));
	z_pos = malloc(sizeof(float *) * (lines));
	while (++i < lines)
		strmat[i] = ft_split(get_next_line(fd), ' ');
	strmat[i + 1] = NULL;
	i = -1;
	while (++i < lines)
	{
		j = -1;
		z_pos[i] = malloc(sizeof(float) * rows);
		while (++j < rows)
			z_pos[i][j] = (float)ft_atoi(strmat[i][j]);
	}
	close(fd);
	return (z_pos);
}
