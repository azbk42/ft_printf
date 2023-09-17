

#include "ft_printf.h"

void ft_putchar(const char c, int *count)
{
    write(1, &c, 1);
    (*count)++;
}

void ft_putstr(const char *str, int *count)
{
    int i = 0;
    while (str[i])
    {
        ft_putchar(str[i++], count);
    }
}

void	print_hexa_u(int *count, unsigned int nbr, char letter, int base)
{
	char	*hexa_min;
	char	*hexa_maj;
	char	*decimal;

	hexa_min = "0123456789abcdef";
	hexa_maj = "0123456789ABCDEF";
	decimal = "0123456789";
	if (nbr >= base)
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