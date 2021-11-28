/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:09:47 by rel-fagr          #+#    #+#             */
/*   Updated: 2021/11/27 18:45:26 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_creat_str(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	if (!str)
		return (NULL);
	ft_bzero(str, 1);
	return (str);
}

static int	ft_strchr2(char *s, char c)
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

static unsigned int	len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (ft_strlen(str) == i)
		return (ft_strlen(str) - 1);
	return (i);
}

static char	*ft_read_buf(char *str, int *fd, char *ptr)
{
	int		count_octe;
	char	*buf;

	count_octe = 1;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	ft_bzero(buf, (BUFFER_SIZE + 1));
	while (ft_strchr2(str, '\n'))
	{
		count_octe = read(*fd, buf, BUFFER_SIZE);
		if (count_octe <= 0)
		{
			if (*str)
				break ;
			return (free(buf), free(str), NULL);
		}
		ptr = str;
		str = ft_strjoin(str, buf);
		if (!str)
			return (NULL);
		free(ptr);
		ft_bzero(buf, BUFFER_SIZE);
	}
	return (free(buf), str);
}

char	*get_next_line(int fd)
{
	char			*str;
	static char		*stc;
	char			*fin_tab;
	char			*ptr;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
		ptr = NULL;
	str = ft_creat_str();
	if (stc)
	{
		ptr = str;
		str = ft_strjoin(stc, str);
		free(stc);
		free(ptr);
		stc = NULL;
	}
	str = ft_read_buf(str, &fd, ptr);
	if (!str)
		return (NULL);
	fin_tab = ft_substr(str, 0, len(str) + 1);
	if (ft_strlen(fin_tab) != ft_strlen(str))
		stc = ft_substr(str, len(str) + 1, ft_strlen(str + len(str) + 1));
	return (free (str), fin_tab);
}
