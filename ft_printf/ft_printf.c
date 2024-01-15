
#include "libft.h"
#include <stdio.h>

int	check(char c, va_list *ap)
{
	int count;

	count = 0;
	if (c == 's')
		count = ft_putstr_fd(va_arg(*ap,char *), 1);
	else if (c == 'c')
		count = ft_putchar_fd(va_arg(*ap, int), 1);
	else if (c == 'i' || c == 'd')
		ft_putnbr_fd(va_arg(*ap,int), 1, &count);
	else if (c == 'u')
		ft_putuint(va_arg(*ap, unsigned int), 1, &count) ;
	else if (c == 'x' || c == 'X')
		count = ft_puthexa(va_arg(*ap, int), 1, c);
	else if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		count = 2 + ft_putadd(va_arg(*ap, unsigned long int), 1);
	}
	else if(c == '%')
		count = ft_putchar_fd('%', 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
    int		i;
	va_list	ap;
	int count;
	
	count = 0;
	i =0;
	va_start(ap, str);
    while (str[i])
    {
        if (str[i] == '%')
		{
           count += check(str[++i], &ap);
		   if (str[i])
		   	i++;
		}
        else
		{
            write (1, &str[i++], 1);
			count++;
		}
    }
	va_end(ap);
	return (count);
}

int main()
{
	int a = 7;
	int b;
	//4,294,967,295
	//ft_printf("1337 42 %s 42 42 %s  %cnt = %u","nxofo", "wax mzn",'k', 1337);
	// ft_printf("%");
	ft_printf("%");
}