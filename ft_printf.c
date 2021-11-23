#include "libft.h"
#include <stdio.h>
#include <stdarg.h>

//DONE ft_putchar_fd  %c
//DONE ft_putstr_fd   %s
//DONE ft_putpointed_fd %p (pointer arg is printed in hex)
//DONE ft_putnbr_fd   %d (decimal base 10) number
// DONE ft_putint_fd   %i (integer base 10)
//DONE ft_putunsignedint %u (unsigned base 10) number
//DONE ft_puthex_lower_case %x hex in lowercale
//DONE ft_puthex_upper_case %X hex in uppercase
//DONE %% print a percent sign
//DONE printf return s symbols it did print

static int	flag_handler(va_list ap, const char *input_str, int *ind)
{
	int	n_char_printed;
	int	local_ind;

	if (!input_str || !ind)
		return (0);
	*ind += 1;
	local_ind = *ind;
	if (input_str[local_ind] == 'd' || input_str[local_ind] == 'i')
		n_char_printed = ft_putnbr_fd(va_arg(ap, int), 1);
	else if(input_str[local_ind] == 'u')
		n_char_printed = ft_putunsignedint_fd(va_arg(ap, int), 1);
	else if (input_str[local_ind] == 'c')
		n_char_printed = ft_putchar_fd((char)va_arg(ap, int), 1);
	else if (input_str[local_ind] == '%')
		n_char_printed = ft_putchar_fd('%', 1);
	else if (input_str[local_ind] == 's')
		n_char_printed = ft_putstr_fd(va_arg(ap, char *), 1);
	else if (input_str[local_ind] == 'x' || input_str[local_ind] == 'X')
		n_char_printed = ft_putnbr_hex(va_arg(ap, int), input_str[local_ind], 1);
	else if (input_str[local_ind] == 'p')
		n_char_printed = ft_put_void_ptr(va_arg(ap, void *), 1);
	*ind += 1;
	return (n_char_printed);
}

static int	text_handler(const char *input_str, int *ind)
{
	int	start_ind;
	int	n_char_printed;

	if (!input_str || !ind)
		return (0);
	start_ind = *ind;
	while (input_str[*ind] && input_str[*ind] != '%')
		*ind += 1;
	write(1, &input_str[start_ind], *ind - start_ind);
	n_char_printed = *ind - start_ind;
	return (n_char_printed);
}


int	ft_printf(const char *input_str, ...)
{
	int		ind;
	int		len_input_str;
	int		n_printed;

	len_input_str = ft_strlen(input_str);
	va_list	ap;
	ind = 0;
	n_printed = 0;
	va_start(ap, input_str);
	while (ind < len_input_str)
	{
		if (input_str[ind] == '%')
			n_printed += flag_handler(ap, input_str, &ind);
		else
			n_printed += text_handler(input_str, &ind);
	}
	va_end(ap);
	return (n_printed);
}



// int main()
// {
// 	//printf("ABOBA%d", 3);
// 	int a = 0;
// 	int b = 4;
// 	//int c = 5;
// 	//printf("%u\n", a);
// 	printf("our returned %d\n",ft_printf("our unsigned is %u and so long %d please, %c\n", a, b, '~'));
// 	printf("original returned %d\n", printf("our unsigned is %u and so long %d please, %c\n", a, b, '~'));

// 	// ft_printf("Numbers: %d %d %d %c  %s \n", a, b, c,'t', "aboba");
// }
