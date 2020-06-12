/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 20:55:53 by tdontos-          #+#    #+#             */
/*   Updated: 2020/06/07 20:55:54 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	align_stack(t_stk *stk, int num, char *func(char *s, char c, int len))
{
	char	*a_num;
	int		len;
	char	*empty;
	a_num = ft_itoa(num);
	len = (int)ft_strlen(a_num) - stk->dist + 4;
	empty = func(a_num, ' ', (len * -1) + 3);
	ft_putstr(empty);
	ft_strdel(&empty);
	ft_strdel(&a_num);
}

void	print_stack(t_stk *stk)
{
	int		len_a;
	int		len_b;
	char	*empty;

	empty = ft_addnchr_s("", ' ', stk->dist - 1);
	len_a = -1;
	len_b = -1;
	while (len_a < stk->cnt_a || len_b < stk->cnt_b)
	{
		if (++len_a < stk->cnt_a)
			align_stack(stk, stk->a[len_a], ft_addnchr_e);
		else
			ft_putstr(empty);
		if (++len_b < stk->cnt_b)
			align_stack(stk, stk->b[len_b], ft_addnchr_s);
		ft_putchar('\n');
	}
	ft_printf("- %s -\n", empty);
	ft_printf("a %s b\n", empty);
	ft_strdel(&empty);
}

int		split_cmd(char *cmd, t_stk *stk)
{
	char	**cmd_arr;
	char	**p_cmd_arr;
	int		count_cmd;

	count_cmd = 0;
	cmd_arr = ft_strsplit(cmd, ' ');
	p_cmd_arr = cmd_arr;
	while (*cmd_arr)
	{
		count_cmd++;
		check_valid_cmd(*cmd_arr, stk);
		ft_strdel(cmd_arr);
		cmd_arr++;
	}
	free(p_cmd_arr);
	return (count_cmd);
}

void	distance_char(t_stk *stk)
{
	int		max;

	max = stk->max;
	while (max >= 10) {
		max /= 10;
		stk->dist++;
	}
}