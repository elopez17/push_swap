/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 20:11:58 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/13 01:40:18 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_exit(t_pswap *e, int error)
{
	if (error)
		write(2, "\x1b[31;01mError\x1b[0m\n",
									ft_strlen("\x1b[31;01mError\x1b[0m\n"));
	free(e->a);
	free(e->b);
	free(e->sorted);
	exit(0);
}
