/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:20:54 by syolando          #+#    #+#             */
/*   Updated: 2021/11/10 17:56:11 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

static void	str_unsigned_int(int n, char *int_as_chars)
{
	int				delim;
	int				ind;
	unsigned long	nn;

	nn = (unsigned int)n;
	ind = 0;
	delim = 1000000000;
	while (!(nn / delim))
		delim /= 10;
	while (delim != 0)
	{
		int_as_chars[ind] = (nn / delim) % 10 + '0';
		delim /= 10;
		ind++;
	}
	int_as_chars[ind] = 0;
}

int	ft_putunsignedint_fd(int n, int fd)
{
	char		int_as_chars[12];
	int			output_len;

	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	else
	{
		str_unsigned_int(n, int_as_chars);
		output_len = ft_strlen(int_as_chars);
		printf("OUTPUTLEN: %d\n", output_len);
		write(fd, int_as_chars, output_len);
	}
	return (output_len);
}
