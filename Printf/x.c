#include <limits.h>
#include <stdio.h>

int main ()
{
	unsigned long long s = ULLONG_MAX;

	printf("%llu\n", s);
	printf("%llu\n", s / 16);
}
