/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:39:12 by azbk              #+#    #+#             */
/*   Updated: 2023/09/17 19:39:22 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(const char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr(const char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*count) += 6;
		return ;
	}
	while (str[i])
		ft_putchar(str[i++], count);
}

void	print_hexa_u(int *count, unsigned int long nbr, char letter, int base)
{
	char	*hexa_min;
	char	*hexa_maj;
	char	*decimal;

	hexa_min = "0123456789abcdef";
	hexa_maj = "0123456789ABCDEF";
	decimal = "0123456789";
	if (nbr >= (unsigned int)base)
	{
		print_hexa_u(count, nbr / base, letter, base);
		print_hexa_u(count, nbr % base, letter, base);
	}
	else if (letter == 'x')
		ft_putchar(hexa_min[nbr], count);
	else if (letter == 'X')
		ft_putchar(hexa_maj[nbr], count);
	else
		ft_putchar(decimal[nbr], count);
}

void	ft_putnbr(int nb, int *count)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, count);
		ft_putnbr(nbr % 10, count);
	}
	else
		ft_putchar(nb + '0', count);
}

void	print_adress(void *add, int *count)
{
	unsigned long int	nbr;

	nbr = 0;
	if (add == NULL)
		ft_putstr("(nil)", count);
	else
	{
		nbr = (unsigned long int)add;
		printf("nbr = %ld\n", nbr);
		ft_putstr("0x", count);
		print_hexa_u(count, nbr, 'x', 16);
	}
}
