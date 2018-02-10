/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:32:08 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/10 02:15:27 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static int	is_sorted(t_check *e)
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
	t_check	e;

	if (argc <= 1)
		return (0);
	init(&e, argc, argv);
	get_instructions(&e);
	sort_stack(&e);
	if (is_sorted(&e))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	c_exit(&e, 0);
	return (0);
}
