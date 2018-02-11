/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 00:06:40 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/10 20:21:35 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define ABS(x) ((x) < 0 ? -(x) : (x))
# define FALSE 0
# define TRUE 1

typedef struct	s_push_swap
{
	int		*a;
	int		*b;
	int		n_a;
	int		n_b;
}				t_pswap;

void	init(t_pswap *e, int argc, char **argv);
void	sort_stack(t_pswap *e);
void	push_to_a(t_pswap *e);
void	push_to_b(t_pswap *e);
void	rot_stack(int *stack, int n);
void	rev_rot_stack(int *stack, int n);
void	print_stacks(t_pswap *e);
void	ps_exit(t_pswap *e, int error);

#endif
