/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:10:31 by rel-fagr          #+#    #+#             */
/*   Updated: 2021/11/18 15:10:52 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strdup(char *str)
{
	char	*res;
	int		len;
	int		i;

	res = NULL;
	i = 0;
	len = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

//ft_create_str function used in strjoin

char	*ft_create_str(int len)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	return (str);
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
	str = ft_create_str(len);
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
//ft_strchr**************************************************

char	*ft_strchr(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] >= 0)
	{
		if (s[i] == c)
			return (&s[i]);
		else if (s[i] == 0)
			break ;
		i++;
	}
	return (0);
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

size_t	new_lenght(char *str, unsigned int len, unsigned int new_start)
{
	size_t	i;

	i = 0;
	while (str[new_start] && i < len)
	{
		i++;
		new_start++;
	}
	return (i);
}

char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	new_start;

	i = 0;
	ptr = NULL;
	if (!s)
		return (NULL);
	new_start = start;
	if (start > ft_strlen(s))
		return (if_star());
	ptr = (void *)malloc((new_lenght(s, len, new_start) + 1) * sizeof(char));
	if (!ptr)
		return (0);
	while ((i < len) && (s[start] != '\0'))
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}

//ft_calloc*****************************************************

void	*ft_calloc(size_t count, size_t size)
{
	size_t		i;
	char		*res;

	res = NULL;
	i = 0;
	res = malloc(count * size);
	if (!res)
		return (0);
	while (i < count * size)
	{
		res[i] = 0;
		i++;
	}
	return ((void *) res);
}

//********************************
char *ft_strcat(char *s1, char *s2)
{
	int len;
	char *str;
	int i;
	int j;

	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	while(s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while(s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	return(str);
}

//******************************************************

int	ft_strchr2(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}
