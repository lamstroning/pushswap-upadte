#include "push_swap.h"

int		main(int args, char **argv)
{
	if (args <= 1)
		error("empty arguments");
	return (1);
}

void	error(char *msg)
{
	ft_printf("Error: %s\n", msg);
	exit(1);
}