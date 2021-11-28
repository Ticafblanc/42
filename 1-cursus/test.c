#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main(void)
{
	int i = 0;
	int i2 = 0;

	i = printf(" %x ", LONG_MIN);
	printf("%d\n", i);
	i2 = ft_printf(" %x ", LONG_MIN);
	printf("%d",i2);
}
