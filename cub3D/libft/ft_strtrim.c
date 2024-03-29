/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:25:29 by rthomas           #+#    #+#             */
/*   Updated: 2023/04/21 16:57:32 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_is_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*news1;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!s1)
		return (NULL);
	str = (char *)s1;
	while (ft_is_in_set(str[i], set))
		i++;
	while (str[j])
		j++;
	while (ft_is_in_set(str[j - 1], set))
		j--;
	if ((j - i) < 1)
		return (ft_strdup(""));
	news1 = ft_substr(s1, i, (j - i));
	while (i < j)
		news1[k++] = str[i++];
	news1[k] = '\0';
	return (news1);
}
