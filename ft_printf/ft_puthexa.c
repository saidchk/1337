#include "libft.h"

void	puthexa(unsigned int n, int fd,char *base, int *count)
{
	if (n < 16)
		*count += ft_putchar_fd(base[n],1);
	else
	{
		puthexa(n / 16,fd,base, count);
		*count +=ft_putchar_fd(base[n % 16], 1);
	}
}

int	ft_puthexa(int nbr, int fd ,char c)
{
	int		count;
    char	base[] = "0123456789ABCDEF";
    int		i;

	i = 10;
	count = 0;
    if (c == 'x')
        while (i < 16)
		{
			base[i] += 32;
			i++;
		}
	puthexa(nbr, fd, base, &count);
	return (count);
}