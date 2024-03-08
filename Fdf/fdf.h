/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanica- <cmanica-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:13:25 by cmanica-          #+#    #+#             */
/*   Updated: 2024/03/08 19:08:07 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "libft/libft.h"
#include <math.h>

# define LINES 0
# define ROWS 1
# define FD 2

# define WIDTH 1920
# define HEIGHT 1080

# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126
# define MINUS 27
# define PLUS 24
# define SPACE 49
# define KEY_R 15
# define MOUSE_CLICK_LEFT 1
# define MOUSE_CLICK_RIGHT 2
# define MOUSE_CLICK_MIDDLE 3
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define ESCAPE 53
# define ANGLE M_PI_4

typedef struct win
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_win;

typedef struct s_data 
{
	void	*img;
	char	*addr;
	int		bit_pix;
	int		len;
	int		endian;
}	t_data;

typedef struct s_vec3
{
	float		x;
	float		y;
	float		z;
}	t_vec3;

typedef struct s_mat
{
	t_vec3	c1;
	t_vec3	c2;
	t_vec3	c3;
}	t_mat;

int	get_lines(char	*file_name);
int	get_rows(char	*file_name);
int **parser(int fd, int lines, int rows);
void	strmat_free(char ***strmat);
t_vec3	cvec(float x, float y, float z);
t_mat	cmat(t_vec3 vec1, t_vec3 vec2, t_vec3 vec3);
t_mat	*points(int **posz, int lines, int rows);
void	printmat(t_mat mat);
void	center_mat(t_mat *mat, int lines, int rows);
