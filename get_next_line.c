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

// char *check_line_read(char *str)
// {
//     char *fin_tab;
//     int i;

//     i = 0;
//     while(str[i] != '\n')
//         i++;
//     fin_tab = ft_calloc((i + 1), sizeof(char));
//     i = 0;
//     while(str[i] != '\n')
//     {
//         fin_tab[i] = str[i];
//         i++;
//     }
//     fin_tab[i] = '\n';
//     fin_tab[i + 1] = '\0';
//     return(fin_tab);
// }

char    *get_next_line(int fd)
{
    char            *buf;
    char            *str;
    static char     *file_read;
    char            *fin_tab;
    int             count_octe;

    
    count_octe = 1;
    if(BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    if(file_read)
    {
        str = ft_strdup(file_read);
        free(file_read);
    }
    buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
    if(!buf)
        return (NULL);
    count_octe = read(fd, buf, BUFFER_SIZE);
    if(count_octe == 0)
        return (0);
    if(!file_read)
        str = ft_strdup(buf);
    while(count_octe != 0)
    { 
        if(ft_strchr(str, '\n'))
            break;
        count_octe = read(fd, buf, BUFFER_SIZE);
        if(ft_strchr(str, '\n') && count_octe == 0)
        {
            str = ft_strjoin(str, buf);
            break;
        }
        str = ft_strjoin(str, buf);
        if(count_octe == 0)
            return (str);
        if(count_octe == -1)
        {
            free(buf);
            return(NULL);
        }
        
    }
    free(buf);
    fin_tab = ft_substr(str, 0, (ft_strchr(str, '\n') - str + 1));
    file_read = ft_strdup(ft_strchr(str, '\n') + 1);
    free (str);
    return(fin_tab);
}

int main()
{
    int fd;
    int i;
    char    *output;

    i = 200;
    fd = open("42_test.txt", O_RDONLY);
    while(i > 0)
    {
        output = get_next_line(fd);
        if(output)
            printf("%s", output);
        i--;
     }
    close(fd);
}
