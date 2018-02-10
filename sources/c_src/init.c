/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:33:20 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/09 20:33:32 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static int	check_arg(char *arg)
{
	int		i;
	char	*str;

	str = ft_strtrim(arg);
	i = (str[0] == '-') ? 0 : -1;
	while (str[++i] != '\0')
		if (str[i] > '9' || str[i] < '0')
			return (-1);
	return (0);
}

static void	get_stack(t_check *e, char **argv)
{
	int	i;

	i = -1;
	while (++i < e->n_a)
	{
		if (check_arg(argv[i + 1]) == -1)
			c_exit(e, -1);
		e->a[i] = ft_atoi(argv[i + 1]);
	}
}

void	init(t_check *e, int argc, char **argv)
{
	e->n_a = argc - 1;
	e->n_b = 0;
	e->a = (int*)ft_memalloc(sizeof(int) * e->n_a);
	e->b = (int*)ft_memalloc(sizeof(int) * e->n_a);
	get_stack(e, argv);
}
