/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:11:09 by rthomas           #+#    #+#             */
/*   Updated: 2023/04/21 16:51:53 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cub_atoi(const char *str)
{
	long int	i;
	long int	neg;
	long int	result;
	int			nb_char;
	
	nb_char = ft_strlen(str);
	i = 0;
	neg = 1;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
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
	if (nb_char > 3 || (nb_char == 3 && (result * neg) < 100) || (nb_char == 2 && \
		(result * neg) < 10) || nb_char == 0)
		return (-1);
	return (result * neg);
}
