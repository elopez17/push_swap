/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 23:52:05 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/10 00:54:39 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static void sort_stack2(t_check *e, char *instruct)
{
	if (ft_strequ(instruct, "ra") && e->n_a > 1)
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

void	sort_stack(t_check *e)
{
	char	**instructs;
	int		i;

	i = -1;
	instructs = ft_strsplit(e->instructions, ' ');
	while (instructs[++i])
	{
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
		else if (ft_strequ(instructs[i], "pb") && e->n_a > 0)
			push_to_b(e);
		else
			sort_stack2(e, instructs[i]);
	}
	free_2d(&instructs);
}
