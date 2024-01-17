
#include "get_next_line.h"


char	*ft_concat(char *res, char *buffer, int *lenght, int i)
{
    buffer[i] = 0;
	if (*lenght == 0)
		res = ft_strjoin(buffer, "",i,*lenght);
    else
		res = ft_strjoin(res, buffer,*lenght,10239);
	*lenght += i ;
    return (res);
}
char	*get_next_line(int fd)
{
    static char buffer[10240];
    int			i;
    char		c[1];
    static int	lenght;
	char		*res;
    int         bytes;

    i = 0;
	lenght = 0;
	res = buffer;
    if (fd < 0 ||(bytes = read(fd,c,1)) <= 0)
		return NULL;
	buffer[i++] = c[0];
    while(c[0] != '\n' && bytes )
    {
        if (i < 10239)
        {
			if ((bytes = read(fd,c,1)) < 0)
		  		return (NULL);
            if (bytes)
			buffer[i++] = c[0];
        }
        else 
        {
            res = ft_concat(res, buffer, &lenght, i);
            i = 0;
        }
    }
	 buffer[i] = 0;
		if(lenght >= 10239 )
			res = ft_strjoin(res, buffer,lenght,i);
    return  (res);
}
/*
int main()
{

    int fd = open("test.txt",O_RDWR, 0777);
	 
    printf("%s",get_next_line(fd));


   // printf("ll");
}*/