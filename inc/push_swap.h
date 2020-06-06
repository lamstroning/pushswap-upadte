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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# include <fcntl.h>

typedef struct	s_stk
{
	int			*a;
	int			*b;
	int			cnt_a;
	int			cnt_b;
	int			min;
	int			max;
	int			flags[3];
}				t_stk;

/*
	push_swap.c
*/
t_stk	*create_stack(int stk_size, int *a);
char	**parse_string(const char **argv, int len, int *stk_size);
char	**merge_stack(char ****merge, int size);
/*
	validate.c
*/
int 	skip_flags(char **args);
void	error(char *msg);
int		check_validate(char **args, int len, int **a);
int		search_flags(char **args, int len, t_stk *stk);

/*
	flags_list.c
*/
int		check_flag(const char *flag);
int		help_flag(void);

#endif
