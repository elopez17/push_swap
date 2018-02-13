/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:32:08 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/13 02:10:50 by eLopez           ###   ########.fr       */
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

int			main(int argc, char **argv)
{
	t_pswap	e;
	char	*instruction;

	if (argc <= 1)
		return (0);
	init(&e, argc, argv);
//	split_stack(&e);
	while (is_sorted(&e) == FALSE)
	{
		ft_printf("%s\n", (instruction = make_move(&e)));
		ft_strdel(&instruction);
	}
	ps_exit(&e, 0);
	return (0);
}
