#include "push_swap.h"

char ft_putstr(char *arg)
{
    int i;

    i = 0;
    while (arg[i])
    {
        printf("%s", arg[i]);
        i++;
    }
}