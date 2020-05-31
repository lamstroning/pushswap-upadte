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

t_stk	*create_stack(const char **argv, int size)
{

}

int		main(int argc, const char **argv)
{
	t_stk	*stack;

	if (argc <= 1)
		error("empty arguments");
	*stack = check_validate(&argv[1], argc - 2);
	search_flags(&argv[1], argc - 2);
	stack = create_stack(&argv[1], argc);
	// while (*stack)
	// {
	// 	ft_printf("%s\n", *stack);
	// 	*stack = *stack + 1;
	// }
	return (0);
}
