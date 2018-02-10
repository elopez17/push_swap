/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 23:52:05 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/10 00:34:26 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

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
		else if (ft_strequ(instructs[i], "ra") && e->n_a > 1)
			rot_stack(e->a);
		else if (ft_strequ(instructs[i], "rb") && e->n_b > 1)
			rot_stack(e->b);
		else if (ft_strequ(instructs[i], "rr"))
		{
			(e->n_a > 1) ? rot_stack(e->a) : 0;
			(e->n_b > 1) ? rot_stack(e->b) : 0;
		}
		else if (ft_strequ(instructs[i], "rra") && e->n_a > 1)
			rev_rot_stack(e->a);
		else if (ft_strequ(instructs[i], "rrb") && e->n_b > 1)
			rev_rot_stack(e->b);
		else if (ft_strequ(instructs[i], "rrr"))
		{
			(e->n_a > 1) ? rev_rot_stack(e->a) : 0;
			(e->n_b > 1) ? rev_rot_stack(e->b) : 0;
		}
	}
	free_2d(&instructs);
}
