/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:30:36 by rthomas           #+#    #+#             */
/*   Updated: 2023/04/19 13:59:19 by cleblais         ###   ########.fr       */
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
	if (!s1)
		return (0);
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
