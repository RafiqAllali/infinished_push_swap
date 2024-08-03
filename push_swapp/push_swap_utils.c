# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>
#include "push_swap.h"
#include <stdlib.h>

char *ft_strjoin(char *str, char *str1)
{
    int len1 = 0, len2 = 0;
    if (str) {
        while (str[len1])
            len1++;
    }
    if (str1) {
        while (str1[len2])
            len2++;
    }
    char *s = (char *)malloc((len1 + len2 + 2) * sizeof(char));
    if (!s)
        return NULL;
    int i = 0;
    if (str) {
        while (str[i]) {
            s[i] = str[i];
            i++;
        }
    }
    int j = 0;
    if (str1) {
        while (str1[j]) {
            s[i + j] = str1[j];
            j++;
        }
    }
    s[i + j] = '\0';
    return s;
}

long	ft_atoi(const char *str)
{
	int			i;
	long		result;
	int			sign;
	long		tmp;

	result = 0;
	sign = 1;
	i = 0;
	tmp = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		if (result > 2147483647 && sign == 1)
			return (2147483648);
	    if (result > 2147483648 && sign == -1)
			return (2147483649);
		tmp = result;
	}
	return (result * sign);
}