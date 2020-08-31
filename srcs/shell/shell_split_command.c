/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:57:27 by juligonz          #+#    #+#             */
/*   Updated: 2020/08/31 18:05:49 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		is_between_quotes(const char *s, size_t index)
{
	size_t	i;
	int		has_open_quote;
	char	quote_type;

	i = 0;
	has_open_quote = 0;
	while (s[i] && i < index)
	{
		if (ft_in_charset(s[i], "\"'") && !has_open_quote)
		{
			has_open_quote = 1;
			quote_type = s[i];
		}
		else if (quote_type ==  s[i])
			has_open_quote = 0;
		i++;
	}
	return (has_open_quote);
}

static int		count_words(const char *str, char c)
{
	int i;
	int	count_words;

	i = -1;
	count_words = 0;
	while (str[++i])
	{
		if (str[i] != c && (str[i + 1] == c || !str[i + 1]))
			if (!is_between_quotes(str, i + 1))
				count_words++;
	}
	return (count_words);
}

static char		*ft_strdup_to_char(const char *src, char c)
{
	unsigned int	i;
	unsigned int	word_len;
	char			*s;

	i = 0;
	word_len = 0;
	while (src[i] && src[i] != c && !is_between_quotes(src, i))
	{
		word_len++;
		i++;
	}
	if (!(s = malloc(sizeof(char) * (word_len + 1))))
		return (NULL);
	i = 0;
	while (src[i] && (src[i] != c || is_between_quotes(src, i)))
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char			**split_pipeline(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	nb_words;
	char			**res;

	if (!s)
		return (NULL);
	nb_words = count_words(s, c);
		ft_printf("%d\n", nb_words);
	if (!(res = malloc(sizeof(char *) * (nb_words + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < nb_words)
	{
		while (s[j] && s[j] == c) // && !is_between_quotes(s, j))
			j++;
		res[i++] = ft_strdup_to_char(&s[j], c);
		while (s[j] && s[j] != c ) //|| is_between_quotes(s, j)))
			j++;
	}
	res[i] = 0;
	return (res);
}
