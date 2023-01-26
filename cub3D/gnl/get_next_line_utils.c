/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:21:53 by rthomas           #+#    #+#             */
/*   Updated: 2022/04/25 20:22:37 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	int		j;
	char	*str;

	if ((start + len) <= ft_strlen(s))
		str = (char *)malloc(sizeof(char) * len + 2);
	else
		str = (char *)malloc(sizeof(char) * (ft_strlen(s) - start) + 2);
	i = 0;
	j = 0;
	while (s[start] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	if (s && s[start] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(char *s1)
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

char	*ft_strchr(char *s, int c)
{
	char	j;
	int		i;

	j = (char)c;
	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == j)
			return ("ok");
		i++;
	}
	if (s[i] == j)
		return ("ok");
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{	
	int		i;
	int		lens1;
	int		lens2;
	char	*result;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!result)
		return (0);
	i = -1;
	while (++i < lens1)
		result[i] = s1[i];
	i = 0;
	while (i < lens2)
	{
		result[lens1] = s2[i];
		i++;
		lens1++;
	}
	result[lens1] = '\0';
	free(s1);
	return (result);
}
