/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:32:08 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/10 20:22:34 by eLopez           ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_pswap	e;

	if (argc <= 1)
		return (0);
	init(&e, argc, argv);
	print_stacks(&e);
	while (is_sorted(&e) == FALSE)
	{
		;
		print_stacks(&e);
	}
	ps_exit(&e, 0);
	return (0);
}
