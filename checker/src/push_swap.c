/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:55:53 by tdontos-          #+#    #+#             */
/*   Updated: 2019/07/12 20:55:54 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	**merge_stack(char ****merge, int size)
{
	char	**res;
	int		i;
	int		j;
	char	**current;

	i = 0;
	j = -1;
	res = (char**)ft_memalloc(sizeof(char *) * (size + 1));
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

void	clear_memory(t_stk *stk, char **args)
{
	int		i;

	i = -1;
	free(stk->a);
	free(stk->b);
	free(stk);
	while (args[++i] != NULL)
		ft_strdel(&args[i]);
	free(args);
}

int		main(int argc, const char **argv)
{
	t_stk	*stack;
	int		size;
	char	**args_stk;
	int		*a;

	if (argc <= 1)
		error("");
	check_repeat(&argv[1]);
	args_stk = parse_string(&argv[1], argc - 1, &size);
	size = check_validate(args_stk, size, &a);
	stack = create_stack(size, a);
	search_flags(args_stk, argc - 2, stack);
	distance_char(stack);
	check_result(stack);
	clear_memory(stack, args_stk);
	return (0);
}
