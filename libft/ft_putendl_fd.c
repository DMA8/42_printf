/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:20:44 by syolando          #+#    #+#             */
/*   Updated: 2021/11/10 17:57:45 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	output_len;

	if (!s)
		return (0);
	output_len = ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
	return (output_len + 1);
}
