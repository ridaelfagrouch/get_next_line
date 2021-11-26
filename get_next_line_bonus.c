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
    if (strlen(str) == i)
        return (strlen(str) - 1);
    return (i);
}

char    *get_next_line(int fd)
{
    char            *buf;
    char            *str;
    static char     *file_read;
    char            *fin_tab;
    int             count_octe;
    char            *ptr;

    fin_tab = NULL;
    count_octe = 1;
    if(BUFFER_SIZE <= 0 || fd < 0)
        return (0);
    buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
    if(!buf)
        return (NULL);
    str = (char *)ft_calloc(1, sizeof(char));
    if(!str)
        return (NULL);
    str[0] = 0;
    if(file_read)
    {
        ptr = str;
        str = ft_strjoin(file_read, str);
        free(file_read);
        free(ptr);
        file_read = NULL;
    }
    while(ft_strchr2(str, '\n'))
    {
        count_octe = read(fd, buf, BUFFER_SIZE);
        if (count_octe <= 0)
        {
            if(*str)
                break ;
            free (buf);
            free (str);
            return(NULL);
        }
        ptr = str;
        str = ft_strjoin(str, buf);
        free(ptr);
        ft_bzero(buf, BUFFER_SIZE);
    } 
    fin_tab = ft_substr(str, 0, ft_check_len(str) + 1);
    if (strlen(fin_tab) != strlen(str))
        file_read = ft_strdup(str + ft_check_len(str) + 1);
    free(buf);
    free (str);
    return(fin_tab);
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