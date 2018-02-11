/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 00:56:05 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/10 19:03:28 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_to_a(t_pswap *e)
{
	int	i;

	--e->n_b;
	++e->n_a;
	i = e->n_a;
	while (--i > 0)
		e->a[i] = e->a[i - 1];
	e->a[0] = e->b[0];
	i = -1;
	while (++i <= e->n_b)
		e->b[i] = e->b[i + 1];
}

void	push_to_b(t_pswap *e)
{
	int	i;

	--e->n_a;
	++e->n_b;
	i = e->n_b;
	while (--i > 0)
		e->b[i] = e->b[i - 1];
	e->b[0] = e->a[0];
	i = -1;
	while (++i <= e->n_a)
		e->a[i] = e->a[i + 1];
}

void	rot_stack(int *stack, int n)
{
	int	i;
	int	hold;

	i = -1;
	hold = stack[0];
	while (++i < n - 1)
		stack[i] = stack[i + 1];
	stack[n - 1] = hold;
}

void	rev_rot_stack(int *stack, int n)
{
	int	i;
	int	hold;

	i = n;
	hold = stack[n - 1];
	while (--i > 0)
		stack[i] = stack[i - 1];
	stack[0] = hold;
}
