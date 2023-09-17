/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:44:44 by azbk              #+#    #+#             */
/*   Updated: 2023/09/17 17:36:12 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putstr(const char *str, int *count);
void	ft_putchar(const char c, int *count);
void	print_hexa_u(int *count, unsigned int nbr, char letter, int base);
void	ft_putnbr(int nb, int *count);

#endif