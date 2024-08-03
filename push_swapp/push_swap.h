#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_hold
{
    long  *numbers;
    long *numbers2;
}t_hold;

long    ft_strlen (long *s);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *str, char *str1);
long	ft_atoi(const char *str);
#endif