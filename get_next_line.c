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

char *fin_line_trouve(char *file_read, int count_octe , char * buf)
{
    char    *new_buf;
    int     i;
    int     j;

    i = 0;
    while(buf[j] != '\n')
        j++;
    while(buf[i] != '\n' && i < count_octe)
    {
        new_buf[i] = buf[i];
    }


}

char    *get_next_line(int fd)
{
    char            *buf;
    static char     *file_read;
    char            *new_file;
    int             i;
    int             count_octe;
    
    if(BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); 
        if(!buf)
            return(NULL);
    count_octe = read(fd, buf, BUFFER_SIZE);
    buf[count_octe] = '\0';
    if(!strchr(buf, '\n') &&  count_octe > 0)
    {
        file_read = (char *)malloc(sizeof(char) * (ft_strlen(buf) + 1));
        while(i < BUFFER_SIZE)
        {
            file_read[i] = buf[i];
            i++;
        }
        file_read[i] = '\0';
        free(buf);
    }
    else    
        file_read = ft_strdup(fin_line_trouve(file_read, count_octe));
    //file_read = ft_strjoin(file_read, buf);
    


}
