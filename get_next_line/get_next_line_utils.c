#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2,int s1_len, int s2_len)
{
	char	*str;
	int		i;
	i = 0;

	if (!s1 || !s2)
		return (0);
	str = malloc( s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
    {
		str[s1_len++] = s2[i++];
    }
	str[s1_len] = '\0';
	return (str);
}
