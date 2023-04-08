/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainthomas <romainthomas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:11:09 by rthomas           #+#    #+#             */
/*   Updated: 2023/04/07 14:11:06 by romainthoma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	i;
	long int	neg;
	long int	result;

	i = 0;
	neg = 1;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	// if ((str[i] == '+') || (str[i] == '-'))
	// {
	// 	if (str[i] == '-')
	// 		neg *= -1;
	// 	i++;
	// }
	result = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		result = result * 10 + ((str[i] - '0'));
		i++;
	}
	if (result > 2147483647 || result < -2147483648)
		return (-1);
	return (result * neg);
}
