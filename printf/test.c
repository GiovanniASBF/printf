#include <stdio.h>
int	main(void)
{
	int	hex = 2515;
	int	*pt = &hex;

	printf("result: %p\n", pt);
}
