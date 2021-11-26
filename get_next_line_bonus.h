/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:09:59 by rel-fagr          #+#    #+#             */
/*   Updated: 2021/11/18 15:10:04 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 1
// # endif

char    *get_next_line(int fd);
size_t  ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_create_str(int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, char c);
char	*if_star(void);
size_t	new_lenght(char *str, unsigned int len, unsigned int new_start);
char	*ft_substr(char *s, unsigned int start, unsigned int len);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char    *ft_strcat(char *s1, char *s2);
int     ft_strchr2(char *s, char c);
void	ft_bzero(void *s, size_t n);

#endif
