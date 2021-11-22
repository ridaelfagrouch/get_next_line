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

char *trouve_new_line(char *buf)
{
    char *new_buf;
    size_t i;
    char *fin_tab;

    i = 0;
    while(buf[i] != '\n')
        i++;
    new_buf = ft_substr(buf, 0, (i + 1));
    if(!new_buf)
        return (0);
    fin_tab = ft_strdup(new_buf);
    if(!fin_tab)
        return (NULL);
    free (buf);
    free (new_buf);
    return (fin_tab);
}

char    *get_next_line(int fd)
{
    char            *buf;
    static char     *file_read;
    int             count_octe;
    
    buf = NULL;
    if(BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
 
    while(!ft_strchr(buf, '\n') && count_octe != 0)
    {
        count_octe = 1;
        free(buf);
        buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if(!buf)
            return(NULL);
        count_octe = read(fd, buf, BUFFER_SIZE);
        if(count_octe == 1)
        {
            free(buf);
            return (0);
        }
        buf[count_octe] = '\0'; 
        if(ft_strchr(buf, '\n'))
            break;
        file_read = ft_strjoin(file_read, buf);
    }
    file_read = ft_strjoin(file_read, trouve_new_line(buf));
    return(file_read);
}

int main()
{
    int fd;

    fd = open("get_next_line.c", O_RDONLY);
    printf("%s", get_next_line(fd));
}
