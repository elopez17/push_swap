/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 20:44:23 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/11 18:12:39 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static char	*make_move3(t_pswap *e)
{
	if (e->n_b > 1 && check_rrb(e))
	{
		rev_rot_stack(e->b, e->n_b);
		return (ft_strdup("rrb"));
	}
	if (e->n_a > 2 && !a_is_sorted(e))
	{
		push_to_b(e);
		return (ft_strdup("pb"));
	}
	push_to_a(e);
	return (ft_strdup("pa"));
}

static char	*make_move2(t_pswap *e)
{
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
	return (make_move3(e));
}

char		*make_move(t_pswap *e)
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
	return (make_move2(e));
}
