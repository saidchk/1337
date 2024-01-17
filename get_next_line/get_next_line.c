
#include "get_next_line.h"

int	ft_strcpy(char *buffer, char *c, char *tempbuffer,int j,int *check)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (j == 0)
	while (tempbuffer[k] != 0)
	{
		buffer[j++] = tempbuffer[k++];
	}
	k = 0;
	buffer[j] = c[i];
	j++;
	while (c[i] != '\n' && *check && c[++i] != '\0')
	{
		buffer[j++] = c[i];
	}
	
	if (buffer[j - 1] == '\n' )
	{
		*check = 0;
	}
	if (c[i] == '\n' && c[++i] != 0)
	while (c[i] != '\0')
		tempbuffer[k++] = c[i++];
	tempbuffer[k] = 0;
	return (j);
}

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
    char		c[BUFF_SIZE + 1];
    static char tempbuffer[BUFF_SIZE];
    static int	lenght;
	char		*res;
	int			check;

    i = 0;
	lenght = 0;
	res = buffer;
	c[BUFF_SIZE] = 0;
    if (fd < 0 ||(check = read(fd,c,BUFF_SIZE)) <= 0 || BUFF_SIZE <= 0 )
		return NULL;
	i = ft_strcpy(buffer, c, tempbuffer,i,&check);
	while(check)
    {
        if (i < 10239)
        {
			if ((check = read(fd,c,BUFF_SIZE)) < 0)
		  		return (NULL);
			i = ft_strcpy(buffer, c, tempbuffer,i,&check);
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
  
int main()
{

    int fd = open("test.txt",O_RDWR, 0777);
	 
   get_next_line(fd);
 
  // printf("%s",get_next_line(fd));
   // printf("%s",get_next_line(fd));
  // printf("ll");
}