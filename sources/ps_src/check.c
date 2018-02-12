/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 20:44:23 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/11 18:00:30 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	a_is_sorted(t_pswap *e)
{
	int	i;
	int	j;

	i = e->n_a;
	while (--i > 0)
	{
		j = i;
		while (--j >= 0)
			if (e->a[j] > e->a[i])
				return (0);
	}
	return (1);
}

int	check_rra(t_pswap *e)
{
	int	i;

	i = -1;
	while (++i < e->n_a - 1)
	{
		if (e->a[i] < e->a[e->n_a - 1])
			return (0);
	}
	return (1);
}

int	check_rrb(t_pswap *e)
{
	int	i;

	i = -1;
	while (++i < e->n_b - 1)
	{
		if (e->b[i] > e->b[e->n_b - 1])
			return (0);
	}
	return (1);
}

int	check_ra(t_pswap *e)
{
	int	i;

	i = 0;
	while (++i < e->n_a)
	{
		if (e->a[i] > e->a[0])
			return (0);
	}
	return (1);
}

int	check_rb(t_pswap *e)
{
	int	i;

	i = 0;
	while (++i < e->n_b)
	{
		if (e->b[i] < e->b[0])
			return (0);
	}
	return (1);
}
