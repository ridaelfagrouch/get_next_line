/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:27:53 by rel-fagr          #+#    #+#             */
/*   Updated: 2021/11/27 18:47:17 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_creat_str(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	if (!str)
		return (NULL);
	ft_bzero(str, 1);
	return (str);
}

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

unsigned int	len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (ft_strlen(str) == i)
		return (ft_strlen(str) - 1);
	return (i);
}

char	*ft_read_buf(char *str, int *fd, char *ptr)
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
		free (ptr);
		ft_bzero(buf, BUFFER_SIZE);
	}
	return (free(buf), str);
}

char	*get_next_line(int fd)
{
	char			*str;
	static char		*stc[1024];
	char			*fin_tab;
	char			*ptr;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	ptr = NULL;
	str = ft_creat_str();
	if (stc[fd])
	{
		ptr = str;
		str = ft_strjoin(stc[fd], str);
		free(stc[fd]);
		free(ptr);
		stc[fd] = NULL;
	}
	str = ft_read_buf(str, &fd, ptr);
	if (!str)
		return (NULL);
	fin_tab = ft_substr(str, 0, len(str) + 1);
	if (ft_strlen(fin_tab) != ft_strlen(str))
		stc[fd] = ft_substr(str, len(str) + 1, ft_strlen(str + len(str) + 1));
	return (free (str), fin_tab);
}
/*
int main()
{
    int fd;
    int i;
    char    *output;

    i = 15;
    fd = open("42_test.txt", O_RDONLY);
    output = get_next_line(fd);
    while(i > 0)
    {
        printf("%s", output);
        if(output)
            output = get_next_line(fd);
        i--;
     }
}
*/
