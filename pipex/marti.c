#include <stdio.h>
int	main(int argc, char**argv)
{
	int	i = 0;
	argc = 3;
	while (++i < argc)
		printf("%s\n", argv[i]);
}
