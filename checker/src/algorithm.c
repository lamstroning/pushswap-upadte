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

void	check_result(t_stk *stk)
{
	int		i;

	i = 0;
	read_cmd(stk);
	while (++i < stk->cnt_a)
	{
		if (stk->a[i - 1] > stk->a[i] || stk->cnt_b != 0)
			error("KO!");
	}
	ft_printf("OK!\n");
}

void	read_cmd(t_stk *stk)
{
	char	*cmd;
	int		count_cmd;

	count_cmd = 0;
	print_stack(stk);
	while (get_next_line(0, &cmd))
	{
		if (ft_strlen(cmd) == 0)
			break;
		count_cmd += split_cmd(cmd, stk);
		print_stack(stk);
		ft_strdel(&cmd);
	}
	ft_strdel(&cmd);
}

void	clear_cmd(char **arr)
{
	while (*arr != NULL)
	{
		ft_strdel(&(*arr));
		arr++;
	}
}

void	search_cmd(char *cmd, t_stk *stk)
{
	if (cmd[0] == 's')
		s_swap(stk, cmd[1]);
	else if (cmd[0] == 'p')
		s_push(stk, cmd[1]);
	else if (cmd[0] == 'r' && cmd[2] == '\0')
		s_rotate(stk, cmd[1]);
	else if (cmd[0] == 'r')
		s_rotate_rev(stk, cmd[2]);
}

void	check_valid_cmd(char *cmd, t_stk *stk)
{
	char	**allow_cmd;
	int		i;
	int		len;

	len = ft_chr_rep(CMD_LIST, CMD_SYM);
	i = -1;
	allow_cmd = ft_strsplit(CMD_LIST, CMD_SYM);
	while (allow_cmd[++i])
		if (!ft_strcmp(cmd, allow_cmd[i]))
			break ;
	clear_cmd(allow_cmd);
	free(allow_cmd);
	if (i > len)
		error("Invalid command");
	else
		search_cmd(cmd, stk);
}
