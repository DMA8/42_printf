#include <stdio.h>
#include "libft.h"
int main()
{
	// %s %c %d %i %u %x %X %p %%
	int a = 0;
	int b = 4;
	ft_printf("Address is %p Hello! My firstname is %s my last name is %s I am %x years old\n", &b, "Jovanie", "Jorjo", 51014);
	printf("Address is %p Hello! My firstname is %s my last name is %s I am %x years old\n", &b, "Jovanie", "Jorjo", 51014);
	ft_printf("%s %c %d %i %u %x %X %p %%\n", "asd", 'k', -101, -101, -101, -101, -101, &a);
	printf("%s %c %d %i %u %x %X %p %%", "asd", 'k', -101, -101, -101, -101, -101, &a);

}