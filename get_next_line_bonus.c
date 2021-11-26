/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:09:47 by rel-fagr          #+#    #+#             */
/*   Updated: 2021/11/18 15:09:50 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static unsigned int ft_check_len(char *str)
{
    unsigned int i;

    i = 0;
    while(str[i] != '\n' && str[i])
        i++;
    if (ft_strlen(str) == i)
        return (ft_strlen(str) - 1);
    return (i);
}

char    *get_next_line(int fd)
{
    char            *buf;
    char            *str;
    static char     *file_read[1024];
    char            *fin_tab;
    int             count_octe;
    char            *ptr;

    fin_tab = NULL;
    count_octe = 1;
    if(BUFFER_SIZE <= 0 || fd < 0)
        return (0);
    buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if(!buf)
        return (NULL);
    
    ft_bzero(buf, (BUFFER_SIZE + 1));
    str = (char *)malloc(2 * sizeof(char));
    if(!str)
        return (NULL);
    ft_bzero(str, 2);
    if(file_read[fd])
    {
        ptr = str;
        str = ft_strjoin(file_read[fd], str);
        free(file_read[fd]);
        free(ptr);
        file_read[fd] = NULL;
    }
    while(ft_strchr2(str, '\n'))
    {
        count_octe = read(fd, buf, BUFFER_SIZE);
        if (count_octe <= 0)
        {
            if(*str)
                break ;
            return(free(buf), free(str), NULL);
        }
        ptr = str;
        str = ft_strjoin(str, buf);
        free(ptr);
        ft_bzero(buf, BUFFER_SIZE);
    } 
    fin_tab = ft_substr(str, 0, ft_check_len(str) + 1);
    if (ft_strlen(fin_tab) != ft_strlen(str))
        file_read[fd] = ft_substr(str, ft_check_len(str) + 1, ft_strlen(str + ft_check_len(str) + 1));
    return(free(buf), free (str), fin_tab);
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