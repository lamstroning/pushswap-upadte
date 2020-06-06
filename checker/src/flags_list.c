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
	ft_printf("Bonus part:\n");
	ft_printf("Flag -v\n");
	ft_printf("Flag -c\n");
	ft_printf("Flag -h, -help\n\n");
	ft_printf("You can find more of my projects in my github.\n");
	ft_printf("github: \033[94mhttps://github.com/lamstroning\n");
	exit(0);
}

int		check_flag(const char *flag)
{
	if (!ft_strcmp(flag, "-help") || !ft_strcmp(flag, "-h"))
		help_flag();
	else if (!ft_strcmp(flag, "-v"))
			return (0);
	else if (!ft_strcmp(flag, "-c"))
		return (1);
	else if (ft_isalnum(flag[1]))
		return (3);
	else
		error("unknown option. More information -help");
	return (3);
}
