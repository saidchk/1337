
#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
		count++;
	}
	return (count);
}
