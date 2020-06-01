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

int		check_validate(const char **args, int len, int **a)
{
	int		i;
	int		size;
	int		count_elements;


	i = skip_flags(args);
	count_elements = len + (i + 1) * -1;
	if (count_elements <= 1)
		error("please, enter minimum 2 numbers");
	*a = ft_memalloc(sizeof(int) * count_elements);
	size = 0;
	while (++i < len)
	{
		if ((!ft_strchr(args[i], '-')) ||
			(ft_strchr(args[i], '-') && ft_isdigit(args[i][1])))
		{
			(*a)[size] = ft_atoi(args[i]);
			size++;
		}
		else
			error("Invalid value");
	}
	return (size);
}

int		skip_flags(const char **args)
{
	int		count_flags;

	if (ft_strequ(args[0], "-h") || ft_strequ(args[0], "-help"))
		help_flag();
	count_flags = -1;
	if (ft_strequ(args[0], "-v") || ft_strequ(args[0], "-c"))
		count_flags++;
	if (ft_strequ(args[1], "-v") || ft_strequ(args[1], "-c"))
		count_flags++;
	return (count_flags);
}

int		search_flags(const char **args, int len, t_stk *stk)
{
	int		i;
	int		result;

	result = 0;
	i = -1;
	while (i++ < len)
		if (ft_strchr(args[i], '-'))
			stk->flags[check_flag(args[i])]++;
	if (stk->flags[0] > 1 || stk->flags[1] > 1)
		error("flags repeated");
	return (result);
}

void	error(char *msg)
{
	write(2, "Error: ", 7);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);

//	ft_printf("Error: %s\n", msg);
	exit(1);
}