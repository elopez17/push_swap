/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 23:52:05 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/11 17:52:58 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static void	print_stacks(t_check *e)
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
}

static void	sort_stack2(t_check *e, char *instruct)
{
	if (ft_strequ(instruct, "pb") && e->n_a > 0)
		push_to_b(e);
	else if (ft_strequ(instruct, "ra") && e->n_a > 1)
		rot_stack(e->a, e->n_a);
	else if (ft_strequ(instruct, "rb") && e->n_b > 1)
		rot_stack(e->b, e->n_b);
	else if (ft_strequ(instruct, "rr"))
	{
		(e->n_a > 1) ? rot_stack(e->a, e->n_a) : 0;
		(e->n_b > 1) ? rot_stack(e->b, e->n_b) : 0;
	}
	else if (ft_strequ(instruct, "rra") && e->n_a > 1)
		rev_rot_stack(e->a, e->n_a);
	else if (ft_strequ(instruct, "rrb") && e->n_b > 1)
		rev_rot_stack(e->b, e->n_b);
	else if (ft_strequ(instruct, "rrr"))
	{
		(e->n_a > 1) ? rev_rot_stack(e->a, e->n_a) : 0;
		(e->n_b > 1) ? rev_rot_stack(e->b, e->n_b) : 0;
	}
}

void		sort_stack(t_check *e)
{
	char	**instructs;
	int		i;

	i = -1;
	instructs = ft_strsplit(e->instructions, ' ');
	while (instructs[++i])
	{
		(e->options & 2) ? print_stacks(e) : 0;
		(e->options & 1) ? ft_printf("%{rd}%s\n%{nc}", instructs[i]) : 0;
		if (ft_strequ(instructs[i], "sa") && e->n_a > 1)
			SWAPINT(e->a[0], e->a[1]);
		else if (ft_strequ(instructs[i], "sb") && e->n_b > 1)
			SWAPINT(e->b[0], e->b[1]);
		else if (ft_strequ(instructs[i], "ss"))
		{
			(e->n_a > 1) ? SWAPINT(e->a[0], e->a[1]) : 0;
			(e->n_b > 1) ? SWAPINT(e->b[0], e->b[1]) : 0;
		}
		else if (ft_strequ(instructs[i], "pa") && e->n_b > 0)
			push_to_a(e);
		else
			sort_stack2(e, instructs[i]);
	}
	(e->options & 2) ? print_stacks(e) : 0;
	free_2d(&instructs);
}
