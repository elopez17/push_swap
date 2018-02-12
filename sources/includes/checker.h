/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 00:06:40 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/11 17:55:44 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct	s_checker
{
	int		*a;
	int		*b;
	int		n_a;
	int		n_b;
	char	*instructions;
	int		options;
	int		count;
}				t_check;

void			init(t_check *e, int argc, char **argv);
void			get_instructions(t_check *e);
void			sort_stack(t_check *e);
void			push_to_a(t_check *e);
void			push_to_b(t_check *e);
void			rot_stack(int *stack, int n);
void			rev_rot_stack(int *stack, int n);
void			c_exit(t_check *e, int error);

#endif
