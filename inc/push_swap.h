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
# define CMD_LIST "sa|sb|ss|pa|pb|ra|rb|rr|rra|rrb|rrr"
# define CMD_SYM '|'

typedef struct	s_stk
{
	int			*a;
	int			*b;
	int			cnt_a;
	int			cnt_b;
	int			min;
	int			max;
	int			dist;
	int			flags[3];
}				t_stk;

/* push_swap.c */
t_stk			*create_stack(int stk_size, int *a);
char			**parse_string(const char **argv, int len, int *stk_size);
void			clear_memory(t_stk *stk, char **args);
char			**merge_stack(char ****merge, int size);
/*
 * validate.c
*/
int				skip_flags(char **args);
void			error(char *msg);
int				check_validate(char **args, int len, int **a);
int				search_flags(char **args, int len, t_stk *stk);
void			check_repeat(t_stk *stk);
/*
 * flags_list.c
*/
int				check_flag(const char *flag);
int				help_flag(void);
/*
 * command.c
 */
void			s_swap(t_stk *stk, char c);
void			s_push(t_stk *stk, char c);
void			s_rotate(t_stk *stk, char c);
void			s_rotate_rev(t_stk *stk, char c);
void			push_down(int **stk, int max);
/**
 * algorithm
 */

void			check_valid_cmd(char *cmd, t_stk *stk);
void			read_cmd(t_stk *stk);
void			check_result(t_stk *stk);

// utils.c
void			print_stack(t_stk *stk);
int				split_cmd(char *cmd, t_stk *stk);
void			distance_char(t_stk *stk);

#endif
