/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:13:46 by nhirzel           #+#    #+#             */
/*   Updated: 2022/08/18 22:36:50 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3D.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	ii;
	char			*ss;
	unsigned int	si;

	ii = 0;
	i = start;
	if (s == NULL)
		return (0);
	si = ft_strlen(s);
	if (si < start)
		len = 0;
	if (si - start < len)
		ss = malloc(si - start + 1 * sizeof(char));
	else
		ss = malloc((len + 1) * sizeof(char));
	if (ss == NULL)
		return (0);
	while (s[i] != '\0' && i < len + start && start < si)
		ss[ii++] = s[i++];
	ss[ii] = '\0';
	return (ss);
}

char	**foncfree(char **tab, int t_i)
{
	while (t_i > 0)
	{
		free(tab[t_i]);
		t_i--;
	}
	free(tab);
	return (NULL);
}

char	**manqdelign(char *s, char c, char **tab)
{
	int	i;
	int	ii;
	int	t_i;

	i = 0;
	ii = 0;
	t_i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			ii = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			tab[t_i] = ft_substr(s, ii, (i - ii) + 1);
			if (tab[t_i++] == NULL)
				return (foncfree(tab, t_i - 1));
		}
		i++;
	}
	tab[t_i] = NULL;
	return (tab);
}

int	compte(char *s, char c)
{
	int	i;
	int	ii;

	i = 0;
	ii = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			ii++;
		i++;
	}
	return (ii);
}

char	**ft_split(char *s, char c)
{
	int		ii;
	char	**tab;

	if (s == NULL)
		return (0);
	ii = compte(s, c);
	tab = malloc((ii + 1) * sizeof(char *));
	if (tab == NULL)
		return (0);
	tab = manqdelign(s, c, tab);
	return (tab);
}
