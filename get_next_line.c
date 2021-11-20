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
#include <stdio.h>
 #include <fcntl.h>

char *trouve_new_line(char *buf)
{
    char *new_buf;
    int i;
    char *fin_tab;

    i = 0;
    new_buf = (char *)malloc(sizeof(char) *((ft_strlen(buf) + 2)));
    if(!new_buf)
        return (NULL);
    while(i < ft_strlen(buf) && buf[i] <= '\n')
    {
        new_buf[i] = buf[i];
        i++;
    }
    new_buf[i] = '\0';
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


    count_octe = 1;
    buf = NULL;
    if(BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
 
    while(!ft_strchr(buf, '\n'))
    {
        free(buf);
        buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if(!buf)
            return(NULL);
        count_octe += read(fd, buf, BUFFER_SIZE);
        buf[count_octe] = '\0'; 
        if(ft_strchr(buf, '\n'))
            break;
        file_read = ft_strjoin(file_read, buf);
    }
    file_read = ft_strjoin(file_read, trouve_new_line(&buf));
    return(file_read);
}

int main()
{
    int fd;

    fd = open("get_next_line", O_RDONLY);
    printf("%s", get_next_line(fd));

}
