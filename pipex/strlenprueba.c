#include <stdio.h>

int	main(void)
{
	char	*str = "";
	int	i = 0;

	while (*str++)
		i++;
	printf("%p", str);
}
