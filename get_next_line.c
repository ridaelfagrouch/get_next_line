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
    return (i);
}

char    *get_next_line(int fd)
{
    char            *buf;
    char            *str;
    static char     *file_read;
    char            *fin_tab;
    int             count_octe;
    unsigned int    len;

    fin_tab = NULL;
    count_octe = 1;
    if(BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    if(file_read)
    {
        str = ft_strdup(file_read);
        free(file_read);
        file_read = NULL;
    }
    buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
    if(!buf)
        return (NULL);

    while(count_octe != 0)
    {
        count_octe = read(fd, buf, BUFFER_SIZE);
        if(count_octe == 0 && !buf)
            return(str);
        if(!str)
            str = ft_strdup(buf);
        else
            str = ft_strjoin(str, buf);
        if(count_octe == -1)
        {
            free(buf);
            return(NULL);
        }
        if(ft_strchr(str, '\n'))
            break;
    }   
    len = ft_check_len(str);
    fin_tab = ft_substr(str, 0, len + 1);
    file_read = ft_strdup(str + len + 1);
    free(buf);
    buf = NULL;
    free (str);
    str = NULL;
    return(fin_tab);
}

int main()
{
    int fd;
    int i;
    char    *output;

    i = 20;
    fd = open("42_test.txt", O_RDONLY);
    while(i > 0)
    {
        output = get_next_line(fd);
        if(output)
            printf("%s", output);
        i--;
     }
}
