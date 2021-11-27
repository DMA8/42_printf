/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:32:07 by syolando          #+#    #+#             */
/*   Updated: 2021/11/24 18:32:07 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *input_str, ...);
int	ft_putunsignedint_fd(int n, int fd);
int	ft_putchar_fd(char c, int fd);
int	ft_putendl_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_hex_fd(unsigned int n, char size, int fd);
int	ft_put_void_ptr_fd(void *a, int fd);
int	ft_strlen(const char *s);

#endif