/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 20:11:58 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/09 20:13:56 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	c_exit(t_check *e, int error)
{
	if (error)
		write(2, "Error\n", 6);
	free(e->a);
	free(e->b);
	exit(0);
}