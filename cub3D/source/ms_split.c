/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:34:05 by cleblais          #+#    #+#             */
/*   Updated: 2023/04/19 16:45:41 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

size_t	ms_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	free_tab_strs(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str[i]);
		free(str);
	}
}

typedef struct s_count
{
	unsigned int	count;
	unsigned int	j;
	unsigned int	start;
	size_t			len;
}	t_count;

static t_count	*ft_count_init(void)
{
	t_count	*nbr;

	nbr = (t_count *)malloc(sizeof(t_count));
	if (!nbr)
	{
		perror("");
		return (NULL);
	}
	nbr->count = 0;
	nbr->j = 0;
	nbr->start = 0;
	nbr->len = 0;
	return (nbr);
}

char	*ms_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (ms_strlen(s) == 0)
		len = 0;
	if (len > ms_strlen(s) - start)
		len = ms_strlen(s) - start;
	if (start > ms_strlen(s) - 1)
		len = 0;
	str = (char *)malloc(sizeof(*str) * (len + 2));
	if (!str)
	{
		perror("");
		return (NULL);
	}
	i = -1;
	while (++i < len)
		str[i] = s[start + i];
	str[i] = '\0';
	str[i + 1] = '\0';
	return (str);
}

static void	ft_fillstrs(char *s, char c, char **strs, t_count *n)
{
	unsigned int	i;

	i = 0;
	while (n->j < n->count)
	{
		while (s[i] == c)
			i++;
		n->start = i;
		while (s[i] != c && s[i])
			i++;
		n->len = i - n->start;
		strs[n->j] = ms_substr(s, n->start, n->len);
		if (!strs[n->j])
		{
			free_tab_strs(strs);
			return ;
		}
		n->j++;
	}
	strs[n->j] = 0;
}

char	**ms_split(char *s, char c)
{
	t_count	*n;
	char	**strs;
	int		i;

	if (!s)
		return (NULL);
	n = ft_count_init();
	if (!n)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			n->count++;
	}
	strs = (char **)malloc(sizeof(strs) * (n->count + 1));
	if (!strs)
	{
		free(n);
		perror("");
		return (NULL);
	}
	ft_fillstrs(s, c, strs, n);
	free(n);
	return (strs);
}