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

t_stk	check_validate(const char **args, int len)
{
	int		i;
	int		size;
	t_stk	*stack;

	i = 0;
	while (i++ <= len)
	{
		if ()
	}
}

int		search_flags(const char **args, int len)
{
	int		i;
	int		flags[2];
	int		result;

	result = 0;
	flags[0] = 0;
	flags[1] = 0;
	i = 0;
	while (i++ < len)
		if (ft_strchr(args[i], '-'))
			flags[check_flag(args[i])] = 1;
	if (flags[0])
		result = 1;
	if (flags[1])
		result = 2;
	if (flags[1] && flags[0])
		result = 3;
	return (result);
}

void	error(char *msg)
{
	ft_printf("Error: %s\n", msg);
	exit(1);
}