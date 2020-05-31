/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 19:37:49 by tdontos-          #+#    #+#             */
/*   Updated: 2019/07/12 19:37:51 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		help_flag(void)
{
	ft_printf("Push swap:\n");
	ft_printf("-v: display the stack’s status after each operation\n");
	ft_printf("-c: show in colours the last operation.\n");
	ft_printf("You can find more of my projects in my github.\n");
	ft_printf("github: \033[94mhttps://github.com/lamstroning\n");
	exit(1);
}

int		check_flag(const char *flag)
{
	static int v;
	static int c;

	if (!ft_strcmp(flag, "-help") || !ft_strcmp(flag, "-h"))
		help_flag();
	else if (!ft_strcmp(flag, "-v"))
	{
		v++;
		if (v > 1)
			error("you can use one -v option");
		else
			return (0);
	}
	else if (!ft_strcmp(flag, "-c"))
	{
		c++;
		if (c > 1)
			error("you can use one -c option");
		else
			return (1);
	}
	else if (ft_isalnum(flag[1]))
		return (3);
	else
		error("unknown option. More information -help");
}
