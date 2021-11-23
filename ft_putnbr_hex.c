
#include <unistd.h>

static char	to_hex_digit(unsigned long n, char size)
{
	char	hex_small[7] = {'a', 'b', 'c', 'd', 'e', 'f', 0};
	char	hex_big[7] = {'A', 'B', 'C', 'D', 'E', 'F', 0};

	if (n > 9)
	{	if (size == 'x')
			return hex_small[n - 10];
		else if (size == 'X')
			return hex_big[n - 10];
	}
	return (n + '0');
}

//or unsigned int
static void	print_in_hex(unsigned long n, int *nchars_printed, char size, int fd)
{
	int		remainder;
	char	converted;

	if (n < 16)
	{
		converted = to_hex_digit(n, size);
		write(fd, &converted, 1);
		*nchars_printed += 1;
	}
	else
	{
		remainder = n % 16;
		converted = to_hex_digit(remainder, size);
		print_in_hex(n / 16, nchars_printed, size, fd);
		write(fd, &converted, 1);
		*nchars_printed += 1;
	}
}

int	ft_putnbr_hex(unsigned long n, char size, int fd)
{
	int	n_printed;

	n_printed = 0;
	print_in_hex(n, &n_printed, size, fd);
	return (n_printed);
}

// #include <stdio.h>
// int main()
// {
// 	long	a;
// 	int len;
// 	a = -1;
// 	len = printf("%x", a);
// 	printf("\n%d\n", len);
// 	len = ft_put_hex(a, 'x');
// 	printf("\n%d\n", len);

// }