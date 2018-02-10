/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:33:20 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/09 22:32:46 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static int	check_arg(char *arg)
{
	int			i;
	char		*str;
	int			ret;
	long long	number;

	ret = 0;
	str = ft_strtrim(arg);
	i = (str[0] == '-' || str[0] == '+') ? 0 : -1;
	while (str[++i] != '\0')
		if (str[i] > '9' || str[i] < '0')
			ret = -1;
	number = ft_atoll(str);
	if (i > 11 || number > 2147483647LL || number < -2147483648LL)
		ret = -1;
	ft_strdel(&str);
	return (ret);
}

static void	get_stack(t_check *e, char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (++i < e->n_a)
	{
		if (check_arg(argv[i + 1]) == -1)
			c_exit(e, -1);
		e->a[i] = ft_atoi(argv[i + 1]);
		j = -1;
		while (++j < i)
			if (e->a[j] == e->a[i])
				c_exit(e, -1);
	}

}

void	init(t_check *e, int argc, char **argv)
{
	e->instructions = ft_strdup("");
	e->n_a = argc - 1;
	e->n_b = 0;
	e->a = (int*)ft_memalloc(sizeof(int) * e->n_a);
	e->b = (int*)ft_memalloc(sizeof(int) * e->n_a);
	get_stack(e, argv);
}
