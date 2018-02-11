/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 20:11:58 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/11 12:15:05 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	c_exit(t_check *e, int error)
{
	if (error)
		write(2, "\x1b[31;01mError\x1b[0m\n",
									ft_strlen("\x1b[31;01mError\x1b[0m\n"));
	free(e->a);
	free(e->b);
	ft_strdel(&(e->instructions));
	exit(0);
}
