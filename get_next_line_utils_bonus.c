/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:28:49 by rel-fagr          #+#    #+#             */
/*   Updated: 2021/11/27 13:28:58 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
//ft_substr***********************************************************

char	*if_star(void)
{
	char	*ptr;

	ptr = NULL;
	ptr = (void *)malloc(sizeof(char));
	if (!ptr)
		return (0);
	ptr[0] = '\0';
	return (ptr);
}

char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	new_start;
	size_t			j;

	i = 0;
	j = 0;
	ptr = NULL;
	if (!s)
		return (NULL);
	new_start = start;
	if (start > ft_strlen(s))
		return (if_star());
	while (s[new_start] && j < len)
	{
		j++;
		new_start++;
	}
	ptr = (void *)malloc((j + 1) * sizeof(char));
	if (!ptr)
		return (0);
	while ((i < len) && (s[start] != '\0'))
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
//bzero**************************************************

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*str;

	i = 0;
	str = (char *) s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
