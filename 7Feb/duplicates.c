#include "push_swap.h"

int	check(char *arg)
{
    int i = 0;
    int *fv;

    while (arg[i])
    {
        ++fv[arg[i]];
        ++i;
    }
    int j = 0;
    while (fv[j])
    {
        printf("%d\n", fv[j]);
        ++j;
        if (fv[j] == 2)
            return (0);
    }
	return (1);

}

int	main(int argc, char *argv[])
{
    int j = 0;
    char ** array_char;
    array_char = malloc(sizeof(char *) * (argc - 1));
    while (argc > 1 && argv[j])
	{
		printf("argv[j]: %s", argv[j]);
        array_char[j - 1] = argv[j];
		++j;
	}
    check(*array_char);
    printf("Duplicate %d\n", check(array_char));
    return 1;

}