#include "push_swap.h"

t_stk	*create_stack(int stk_size, int *a)
{
	t_stk	*stk;

	stk = (t_stk*)ft_memalloc(sizeof(t_stk));
	stk->a = a;
	stk->b = (int*)ft_memalloc(sizeof(int) * stk_size);
	stk->max = stk->a[0];
	stk->min = stk->a[0];
	stk->cnt_a = stk_size;
	stk->dist = 5;
	stk->cnt_b = 0;
	stk->flags[0] = 0;
	stk->flags[1] = 0;
	return (stk);
}

char	**merge_stack(char ****merge, int size)
{
	char	**res;
	int		i;
	int		j;
	char	**current;

	i = 0;
	j = -1;
	res = (char**)ft_memalloc(sizeof(char *) * (size + 2));
	current = res;
	while (size >= 0)
	{
		while ((*merge)[i][++j] != NULL)
		{
			*res = ft_strdup((*merge)[i][j]);
			res++;
			ft_strdel(&(*merge)[i][j]);
			size--;
		}
		free((*merge)[i]);
		i++;
		j = -1;
	}
	*res = NULL;
	free(*merge);
	return (current);
}

char	**parse_string(const char **argv, int len, int *stk_size)
{
	char	***tmp;
	int		i;
	int		j;
	int		size;

	j = -1;
	i = -1;
	size = -1;
	tmp = (char***)ft_memalloc(sizeof(char **) * len);
	while (++i < len)
	{
		tmp[i] = ft_strsplit(argv[i], ' ');
		while (tmp[i][++j] != NULL)
			size++;
		j = -1;
	}
	*stk_size = size;
	return (merge_stack(&tmp, size));
}

int		check_validate(char **args, int len, int **a)
{
	int		i;
	int		size;
	int		count_elements;

	i = skip_flags(args);
	count_elements = len + (i + 1) * -1;
	if (count_elements < 1)
		error("please, enter minimum 2 numbers");
	*a = ft_memalloc(sizeof(int) * count_elements);
	size = 0;
	while (++i <= len)
	{
		if ((!ft_strchr(args[i], '-')) ||
			(ft_strchr(args[i], '-') && ft_isdigit(args[i][1])))
			(*a)[size] = ft_atoi(args[i]);
		else
			error("Invalid value");
		size++;
	}
	return (size);
}

void	error(char *msg)
{
	ft_printf("Error: %s\n", msg);
	exit(1);
}

void	check_repeat(t_stk *stk)
{
	int		len;
	int		*repeat;
	int		*p_repeat;
	int		stack_size;

	len = stk->cnt_a;
	while (--len >= 0)
	{
		stk->max = stk->max < stk->a[len] ? stk->a[len] : stk->max;
		stk->min = stk->min > stk->a[len] ? stk->a[len] : stk->min;
	}
	stack_size = stk->max < 0 ? stk->max * -1 : stk->max;
	if (stk->min < 0)
		stack_size += stk->min * -1;
	repeat = (int*)ft_memalloc(sizeof(int) * stack_size);
	repeat = ft_memset(repeat, 0, stk->max);
	p_repeat = stk->min < 0 ? repeat + stk->min * -1 : repeat;
	len = stk->cnt_a;
	while (--len >= 0)
	{
		p_repeat[stk->a[len]]++;
		if (p_repeat[stk->a[len]] == 2)
			error("repeat numbers!");
	}
	free(repeat);
}

int		main(int argc, const char **argv)
{
	char	**args_stack;
	int		size;

	if (argc <= 1)
		error("empty arguments");
	args_stack = parse_string(argv, argc - 1, &size);
	size = check_validate(args_stk, size, &a);
	stack = create_stack(size, a);
	while (size > 0) {
		ft_printf("%s\n", args_stack[--size]);
	}
	return (1);
}
