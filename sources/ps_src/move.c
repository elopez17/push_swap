/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 20:44:23 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/10 22:01:20 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	check_rra(t_pswap *e)
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

static int	check_rrb(t_pswap *e)
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

static int	check_ra(t_pswap *e)
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

static int	check_rb(t_pswap *e)
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

char	*make_move(t_pswap *e)
{
	if (e->n_a > 1 && e->n_b > 1 && e->a[0] > e->a[1] && e->b[0] < e->b[1])
	{
		SWAPINT(e->a[0], e->a[1]);
		SWAPINT(e->b[0], e->b[1]);
		return (ft_strdup("ss"));
	}
	if (e->n_a > 1 && e->a[0] > e->a[1])
	{
		SWAPINT(e->a[0], e->a[1]);
		return (ft_strdup("sa"));
	}
	if (e->n_b > 1 && e->b[0] < e->b[1])
	{
		SWAPINT(e->b[0], e->b[1]);
		return (ft_strdup("sb"));
	}
	if (e->n_a > 1 && e->n_b > 1 && check_ra(e) && check_rb(e))
	{
		rot_stack(e->a, e->n_a);
		rot_stack(e->b, e->n_b);
		return (ft_strdup("rr"));
	}
	if (e->n_a > 1 && check_ra(e))
	{
		rot_stack(e->a, e->n_a);
		return (ft_strdup("ra"));
	}
	if (e->n_b > 1 && check_rb(e))
	{
		rot_stack(e->b, e->n_b);
		return (ft_strdup("rb"));
	}
	if (e->n_a > 1 && e->n_b > 1 && check_rra(e) && check_rrb(e))
	{
		rev_rot_stack(e->a, e->n_a);
		rev_rot_stack(e->b, e->n_b);
		return (ft_strdup("rrr"));
	}
	if (e->n_a > 1 && check_rra(e))
	{
		rev_rot_stack(e->a, e->n_a);
		return (ft_strdup("rra"));
	}
	if (e->n_b > 1 && check_rrb(e))
	{
		rev_rot_stack(e->b, e->n_b);
		return (ft_strdup("rrb"));
	}
	return (ft_strdup("pa"))
}
