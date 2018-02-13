/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:33:20 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/13 02:03:00 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

static void	get_stack(t_pswap *e, char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (++i < e->n_a)
	{
		if (check_arg(argv[i + 1]) == -1)
			ps_exit(e, -1);
		e->a[i] = ft_atoi(argv[i + 1]);
		j = -1;
		while (++j < i)
			if (e->a[j] == e->a[i])
				ps_exit(e, -1);
	}
}

static int	partition(int *arr, int start, int end)
{
	int	pivot;
	int	p_index;
	int	i;

	pivot = arr[end];
	p_index = start;
	i = start - 1;
	while (++i < end)
	{
		if (arr[i] <= pivot)
		{
			SWAPINT(arr[i], arr[p_index]);
			++p_index;
		}
	}
	SWAPINT(arr[p_index], arr[end]);
	return (p_index);
}

static void	quicksort(int *arr, int start, int end)
{
	int	p_index;

	if (start >= end)
		return ;
	p_index = partition(arr, start, end);
	quicksort(arr, start, p_index - 1);
	quicksort(arr, p_index + 1, end);
}

void		init(t_pswap *e, int argc, char **argv)
{
	e->n_a = argc - 1;
	e->n = e->n_a;
	e->n_b = 0;
	e->mid = e->n / 2;
	if ((e->n % 2))
		++e->mid;
	e->a = (int*)ft_memalloc(sizeof(int) * e->n_a);
	e->b = (int*)ft_memalloc(sizeof(int) * e->n_a);
	get_stack(e, argv);
	e->sorted = (int*)ft_memalloc(sizeof(int) * e->n_a);
	ft_memcpy(e->sorted, e->a, sizeof(int) * e->n);
	quicksort(e->sorted, 0, e->n - 1);
}
