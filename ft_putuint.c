#include "libft.h"

void	ft_putuint(unsigned int nb, int fd, int *count)
{
	if (nb < 10)
		*count += ft_putchar_fd(nb + '0', fd);
	else
	{
		ft_putuint(nb / 10, fd, count);
		*count += ft_putchar_fd((nb % 10) + 48, fd);
	}
}
