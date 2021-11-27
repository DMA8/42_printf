/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:21:09 by syolando          #+#    #+#             */
/*   Updated: 2021/11/24 18:20:30 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putstr_fd(char *s, int fd)
{
	int	output_len;

	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	output_len = ft_strlen(s);
	write(fd, s, output_len);
	return (output_len);
}
