/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 22:14:52 by elopez            #+#    #+#             */
/*   Updated: 2018/02/09 21:05:56 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *str)
{
	int			i;
	long long	sign;
	long long	num;

	i = 0;
	num = 0;
	sign = 1;
	while (*(str + i) == ' ' || *(str + i) == '\n' || *(str + i) == '\t' ||
	*(str + i) == '\v' || *(str + i) == '\r' || *(str + i) == '\f')
		i++;
	if (*(str + i) == '-')
		sign = -1LL;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (*(str + i) >= '0' && *(str + i) <= '9')
		num = num * 10LL + (*(str + i++) - '0');
	return (sign * num);
}
