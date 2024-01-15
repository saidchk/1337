#include "libft.h"
#include <stdio.h>

void	putadd(unsigned long int n, int fd,char *base, int *count)
{
	if (n < 16)
		*count += ft_putchar_fd(base[n],1);
	else
	{
		putadd(n / 16,fd,base, count);
		*count +=ft_putchar_fd(base[n % 16], 1);
	}
}

int	ft_putadd(unsigned long int n, int fd)
{
	int		count;
    char	base[] = "0123456789ABCDEF";
 
	count = 0;
    putadd(n, fd, base, &count);
	return (count);
}