/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:32:08 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/13 14:47:29 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	is_sorted(t_pswap *e)
{
	int	i;
	int	j;

	i = e->n_a;
	if (e->n_b > 0)
		return (0);
	while (--i > 0)
	{
		j = i;
		while (--j >= 0)
			if (e->a[j] > e->a[i])
				return (0);
	}
	return (1);
}
/*
static void	print_stacks(t_pswap *e)
{
	int	i;

	i = -1;
	while (++i < e->n_a || i < e->n_b)
	{
		if (e->options & 8)
			ft_printf("%{TQ}");
		if (i < e->n_a)
			ft_printf("%d\t", e->a[i]);
		else
			ft_printf("\t");
		if (e->options & 8)
			ft_printf("%{PU}");
		if (i < e->n_b)
			ft_printf("%d\n", e->b[i]);
		else
			ft_printf("\n");
	}
	ft_printf("-------------\n%{nc}");
}*/

/* 5	4
 * 6	3
 * 7	2
 * 8 	1
 * MID = 4
*/

static int	findindex(t_pswap *e, int numb)
{
	int	i;

	i = -1;
	while (++i < e->n)
	{
		if (e->sorted[i] == numb)
			break ;
	}
	return (i);
}

static void	split_stack(t_pswap *e)
{
	int	i;

	i = -1;
	while (++i < e->n)
	{
		if (findindex(e, e->a[0]) < e->mid && e->n_a > 0)
		{
			push_to_b(e);
			ft_printf("pb\n");
		}
/*		else if (e->n_a > 1 && e->n_b > 1 && check_ra(e) && check_rb(e))
		{
			rot_stack(e->a, e->n_a);
			rot_stack(e->b, e->n_b);
			ft_printf("rr\n");
		}*/
		else
		{
			rot_stack(e->a, e->n_a);
			ft_printf("ra\n");
		}
	}
}

int			main(int argc, char **argv)
{
	t_pswap	e;
	char	*instruction;

	if (argc <= 1)
		return (0);
	init(&e, argc, argv);
	split_stack(&e);
	while (is_sorted(&e) == FALSE)
	{
		ft_printf("%s\n", (instruction = make_move(&e)));
		ft_strdel(&instruction);
	}
	ps_exit(&e, 0);
	return (0);
}
