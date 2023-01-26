/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:42:30 by rthomas           #+#    #+#             */
/*   Updated: 2022/04/05 13:38:49 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_malloc_error(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	return (0);
}

void	ft_cpy(int j, int old_j, char *str, char *dest)
{
	int	i;

	i = 0;
	while (old_j < j)
	{		
		dest[i] = str[old_j];
		i++;
		old_j++;
	}
	dest[i] = '\0';
}

int	ft_where_are_the_j(char *str, char c, int j, int wich_j)
{
	if (wich_j == 0)
	{
		if (j != 0)
			j++;
		while (str[j] && str[j] == c)
			j++;
		return (j);
	}
	if (wich_j == 1)
	{
		while (str[j] && str[j] != c)
			j++;
		return (j);
	}
	return (0);
}

int	get_nb_strs( char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*str)
	{
		if (*str != c && j == 0)
		{
			j = 1;
			i++;
		}
		else if (*str == c)
			j = 0;
		str++;
	}
	return (i);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		old_j;
	int		nb_strs;

	i = 0;
	j = 0;
	nb_strs = get_nb_strs((char *)s, c);
	tab = (char **)malloc(sizeof(char *) * (nb_strs) + 1);
	while (i < nb_strs)
	{
		old_j = ft_where_are_the_j((char *)s, c, j, 0);
		j = ft_where_are_the_j((char *)s, c, old_j, 1);
		tab[i] = (char *)malloc(sizeof(char) * (j - old_j) + 1);
		if (!tab[i])
			return (ft_malloc_error(tab));
		ft_cpy(j, old_j, (char *)s, tab[i]);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
