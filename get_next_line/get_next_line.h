
# ifndef get_next_line_h
#define get_next_line_h

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2,int s1_len, int s2_len);
#endif