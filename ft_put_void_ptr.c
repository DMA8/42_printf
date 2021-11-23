#include <unistd.h>
#include "libft.h"

// static char	to_hex_digit(unsigned long n)
// {
// 	char	hex_small[7] = {'a', 'b', 'c', 'd', 'e', 'f', 0};

// 	if (n > 9)
// 		return hex_small[n - 10];
// 	return (n + '0');
// }

// static void	print_in_hex(unsigned long n, int *nchars_printed, int fd)
// {
// 	int		remainder;
// 	char	converted;

// 	if (n < 16)
// 	{
// 		converted = to_hex_digit(n);
// 		write(fd, &converted, 1);
// 		*nchars_printed += 1;
// 	}
// 	else
// 	{
// 		remainder = n % 16;
// 		converted = to_hex_digit(remainder);
// 		print_in_hex(n / 16, nchars_printed, fd);
// 		write(fd, &converted, 1);
// 		*nchars_printed += 1;
// 	}
// }

// static int	ft_put_hex(unsigned long n, char size, int fd)
// {
// 	int	n_printed;

// 	n_printed = 0;
// 	print_in_hex(n, &n_printed, fd);
// 	return (n_printed);
// }

int	ft_put_void_ptr(void *a, int fd)
{
	int	len;

	if (!a)
		return 0;
	write(fd, "0x", 2);
	len = ft_putnbr_hex((unsigned long)a, 'x', fd);
	len += 2;
	return (len);
}

// #include <stdio.h>ma
// int main()
// {
// 	int	a;
// 	int len;
// 	a = 12;
// 	len = printf("%p", &a);
// 	printf("\n%d\n", len);
// 	len = ft_put_void_ptr(&a);
// 	printf("\n%d\n", len);

// }