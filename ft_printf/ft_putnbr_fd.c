

#include "libft.h"

int	ft_putnbr_fd(int n, int fd, int *count)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
		*(count++);
	}
	if (nb < 10)
		*count += ft_putchar_fd(nb + '0', fd);
	else
	{
		ft_putnbr_fd(nb / 10, fd, count);
		*count += ft_putchar_fd((nb % 10) + 48, fd);
	}
}
