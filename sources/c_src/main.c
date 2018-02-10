/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:32:08 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/09 23:35:11 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

int main(int argc, char **argv)
{
	t_check	e;

	if (argc <= 1)
		return (0);
	init(&e, argc, argv);
	get_instructions(&e);
	sort_stack(&e);
	c_exit(&e, 0);
	return (0);
}
