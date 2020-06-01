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

	stk = ft_memalloc(sizeof(t_stk));
	stk->a = a;
	stk->b = ft_memalloc(sizeof(int) * stk_size);
	stk->max = stk_size;
	stk->min = 0;
	stk->cnt_a = stk_size;
	stk->cnt_b = 0;
	stk->flags[0] = 0;
	stk->flags[1] = 0;
	return (stk);
}

int		main(int argc, const char **argv)
{
	t_stk	*stack;
	int		size;
	int		*a;
	if (argc <= 1)
		error("empty arguments");
	size = check_validate(&argv[1], argc - 1, &a);
	stack = create_stack(size, a);
	search_flags(&argv[1], argc - 2, stack);
	while (stack->cnt_a--)
	{
		ft_putnbr(stack->a[stack->cnt_a]);
		ft_putchar('\n');
	}
	return (0);
}
