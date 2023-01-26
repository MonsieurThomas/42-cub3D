/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:30:36 by rthomas           #+#    #+#             */
/*   Updated: 2022/04/01 19:33:26 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	newstr = (char *)malloc(sizeof (char) * (i + 1));
	if (!newstr)
		return (0);
	while (s1[j])
	{
		newstr[j] = s1[j];
		j++;
	}
	newstr[j] = s1[j];
	return (newstr);
}
