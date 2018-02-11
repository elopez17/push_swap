/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 23:52:05 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/10 19:12:41 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_stacks(t_pswap *e)
{
	int	i;

	i = -1;
	while (++i < e->n_a || i < e->n_b)
	{
		if (i < e->n_a)
			ft_printf("%d\t", e->a[i]);
		else
			ft_printf("\t");
		if (i < e->n_b)
			ft_printf("%d\n", e->b[i]);
		else
			ft_printf("\n");
	}
	ft_printf("-------------\n");
}
