
#include "get_next_line.h"

char	*get_next_line(int fd)
{
    static char buffer[10240];
    int			i;
    char		c[1];
    static int	lenght;
	char		*res;

    i = 0;
	lenght = 0;
	res = buffer;
	
    if (fd < 0 || read(fd,c,1) < 0)
		return NULL;
	buffer[i++] = c[0];
    while(c[0] != '\n' && c[0] != '\0')
    {
        if (i < 10239)
        {
			if (read(fd,c,1) < 0)
		  		return (NULL);
			buffer[i++] = c[0];
        }
        else 
        {
            buffer[i] = 0;
			if (lenght == 0)
           		res = ft_strjoin(buffer, "",i,lenght);
		   else
		   {
				printf("%s\n\n",res);
		   		res = ft_strjoin(res, buffer,lenght,10239);
		   }
		   lenght += i ;
			i = 0;
        }
    }
	 buffer[i] = 0;
		if(lenght >= 10239 )
		{
			res = ft_strjoin(res, buffer,lenght,i);
		}
    return  (res);
}
/*
int main()
{

    int fd = open("test.txt",O_RDWR, 0777);
	 
		//ft_get_next_line(fd);
    printf("%s",ft_get_next_line(fd));
  //  printf("%s",ft_get_next_line(fd));
}*/