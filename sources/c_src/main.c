/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:32:08 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/11 11:52:18 by eLopez           ###   ########.fr       */
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

	if (argc <= 1 || (argc == 2 && argv[1][0] == '-'))
		return (0);
	init(&e, argc, argv);
	get_instructions(&e);
	sort_stack(&e);
	if (is_sorted(&e))
		ft_printf("%{GR}OK%{nc}\n");
	else
		ft_printf("%{RD}KO%{nc}\n");
	if (e.options & 4)
		ft_printf("number of instructions: %d\n", e.count);
	c_exit(&e, 0);
	return (0);
}
