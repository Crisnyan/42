/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanica- <cmanica-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:13:25 by cmanica-          #+#    #+#             */
/*   Updated: 2024/03/01 18:37:51 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "libft/libft.h"

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

typedef struct pos
{
	int		x;
	int		y;
	float	z;
}	t_pos;

float **parser(int fd, int lines, int rows);
int	get_lines(char	*file_name);
t_pos	**points(float **mat, int lines, int rows, t_data img);
int	get_rows(char	*file_name);
