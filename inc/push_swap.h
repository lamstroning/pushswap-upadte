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
}				t_stk;

/*
	push_swap.c
*/
t_stk	*create_stack();


/*
	validate.c
*/
void	error(char *msg);
t_stk	check_validate(const char **args, int len);
int		search_flags(const char **args, int len);

/*
	flags_list.c
*/
int		check_flag(const char *flag);
int		help_flag(void);

#endif
