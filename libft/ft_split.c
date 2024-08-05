/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarustam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:28:04 by aarustam          #+#    #+#             */
/*   Updated: 2024/02/16 13:28:06 by aarustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wc(const char *str, char c)
{
	int	count ;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			i++;
		}
		else
		{
			count++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
	}
	return (count);
}

char	*putword(const char *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (*s && *s == c)
		s++;
	while (s[i] != c && s[i] != '\0')
		i++;
	word = (char *)malloc(i + 1);
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	ft_free(int j, char **p)
{
	while (j > 0)
	{
		free (p[j - 1]);
		j--;
	}
	free(p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		j;
	int		wc;

	if (!s)
		return (NULL);
	wc = ft_wc(s, c);
	p = (char **)malloc((wc + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	j = 0;
	while (j < wc)
	{
		while (*s && *s == c)
			s++;
		p[j] = putword(s, c);
		if (!p[j])
			ft_free(j, p);
		j++;
		while (*s && *s != c)
			s++;
	}
	p[j] = 0;
	return (p);
}
/*
#include <stdio.h>
int main()
{
	int i = 0;
	char **tab;
	
	printf("%d\n",ft_wc("you are a salty", ' '));

	tab = ft_split("   lpllpk wdpokw p kdpowk   ", ' ');
	while (i < 4)
	{
		printf("string %d : %s\n", i, tab[i]);
		i++;
	}
	return (0);
}
*/
