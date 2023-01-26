/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:36:13 by rthomas           #+#    #+#             */
/*   Updated: 2022/04/05 13:42:02 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	j;
	int		i;

	j = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == j)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == j)
		return ((char *)s + i);
	return (0);
}
