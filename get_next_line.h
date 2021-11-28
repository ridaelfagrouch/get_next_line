/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:09:59 by rel-fagr          #+#    #+#             */
/*   Updated: 2021/11/27 18:23:01 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char			*get_next_line(int fd);
size_t			ft_strlen(char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*if_star(void);
char			*ft_substr(char *s, unsigned int start, unsigned int len);
void			ft_bzero(void *s, size_t n);

#endif
