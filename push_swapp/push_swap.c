#include <i386/limits.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

int valid(char **av)
{
    int i = 1;
    int j;

    while (av[i])
    {
        j = 0;
        while (av[i][j] == ' ')
            j++;
        if (av[i][j] == '-' || av[i][j] == '+')
            j++;
        if (av[i][j] == '\0' || !(av[i][j] >= '0' && av[i][j] <= '9'))
            return (1);
        while (av[i][j])
        {
            if (!(av[i][j] >= '0' && av[i][j] <= '9'))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
char  *get_all(char **av)
{
    int i = 1;
    char *all = NULL;
    while (av[i])
    {
        all =ft_strjoin (all, av[i]);
        all = ft_strjoin(all, " ");
        i++;
    }
    return (all);
}

 long *get_int(char **tab)
{
    int i = 0;
    long *tab_int;
    int size = 0;

    while (tab[size])
        size++;
    tab_int = malloc(sizeof(int) * size);
    if (!tab_int)
        return (NULL);
    while (i < size)
    {
        tab_int[i] = ft_atoi(tab[i]);
        i++;
    }
    return (tab_int);
}
long duplicate(long *tab)
{
    int i = 0;
    int j;

    while (tab[i])
    {
        j = i + 1;
        while (tab[j])
        {
            if (tab[i] == tab[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
int range(long *tab, int size)
{
    int i = 0;

    while (i < size)
    {
        if (tab[i] > 2147483647 || tab[i] < -2147483648)
            return (1);
        i++;
    }
    return (0);
}
void ft_sa(long *stack_a)
{
    long tmp;
    if(!stack_a[1])
        return ;
    tmp = stack_a[0];
    stack_a[0] = stack_a[1];
    stack_a[1] = tmp;
}
void ft_sb(long *stack_b)
{
    long tmp;

    if(!stack_b[1])
        return ;
    tmp = stack_b[0];
    stack_b[0] = stack_b[1];
    stack_b[1] = tmp;
}
void ft_ss(long *stack_a, long *stack_b)
{
    ft_sa(stack_a);
    ft_sb(stack_b);
}

void ft_pa(long *stack_a, long *stack_b)
{
    int i = 0;
    while (stack_a[i])
        i++;
    while (i > 0)
    {
        
        stack_a[i] = stack_a[i - 1];
        i--;
    }
    stack_b[0] = stack_a[0];
    // 
}
// void ft_pb(long *stack_a, long *stack_b)
// {
//     ft_pa(stack_b, stack_a);
// }
void sort(long *stack_a, long *stack_b, int size)
{
// if (size == 1)
    // return ;
    if (size == 2)
    {
        // if (stack_a[0] > stack_a[1])
        // {
        //     ft_sa(stack_a);
        //     printf("%ld\n", stack_a[0]);
        //     write(1, "sa\n", 3);
        // }
        ft_pa(stack_a, stack_b);
        // ft_pa( stack_a, stack_b);
        // int i = 0;
        // while (stack_a[i])
        // {
        //     printf("%ld\n", stack_a[0]);
        //     stack_a++;
        // }
    int i = 0;
        while (i < size)
        {
        //     stack_b[i] = stack_a[i];
            printf("stack_a = %ld\n",stack_a[i]);
            printf("stack_b = %ld\n",stack_b[i]);

        //     // exit(0);
            i++;
        }
    }
}
int parsing(char **av)
{
    if (valid(av) == 1)
        return (1);

    char *all = get_all(av);
    char **tab = ft_split(all, ' ');
    long *stack_a = get_int(tab);
    long *stack_b;
    int size = 0;
    while (tab[size])
        size++;
    stack_b = malloc(sizeof(long) * size);
    if (duplicate(stack_a) == 1 || range(stack_a, size) == 1)
        return (1);
    sort(stack_a, stack_b, size);
    return (0);
}
int main (int ac, char **av)
{
    if (ac > 1)
    {
    if (parsing(av) == 1)
        {
            write(1, "Error\n", 6);
            return 0;
        }
    }
    return 0;
}