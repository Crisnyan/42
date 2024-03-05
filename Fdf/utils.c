/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanica- <cmanica-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:09:36 by cmanica-          #+#    #+#             */
/*   Updated: 2024/03/05 17:24:43 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float **parser(int fd, int lines, int rows)
{
	char	***strmat;
	int		i;
	int		j;
	t_mat	**mat;

	i = -1;
	strmat = malloc(sizeof(char**) * (lines + 1));
	mat = malloc(sizeof(float *) * (lines));
	while (++i < lines)
		strmat[i] = ft_split(get_next_line(fd), ' ');
	i = -1;
	while (++i < lines)
	{
		j = -1;
		mat[i] = malloc(sizeof(float) * rows);
		while (++j < rows)
			mat[i][j] = (float)ft_atoi(strmat[i][j]);
	}
	close(fd);
	return (free(strmat), mat);
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

	fd = open(file_name, O_RDONLY);
	strmat = ft_split(get_next_line(fd), ' ');
	rows = 0;
	while (strmat)
		rows++;
	while (str)
		str = get_next_line(fd);
	close(fd);
	return (rows);
}
