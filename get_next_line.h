/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:06:53 by chrstein          #+#    #+#             */
/*   Updated: 2023/11/20 20:06:56 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

# include <unistd.h>
# include <stdlib.h>

#include <stdio.h> //a vireeeeeeeeeeeeeeeeeeeeeeeeeeeeer

// typedef struct s_struct
// {
// 	char        buf[BUFFER_SIZE + 1];
//     char        *stash;
//     char        *stash_tmp;
//     char        *line;
//     ssize_t     bytes_read;
// 	size_t		i;
// }	t_struct;

typedef struct s_struct
{
	char        buf[BUFFER_SIZE + 1];
    char        *tmp;
    char        *tmp_tmp;
    char        *line;
    ssize_t     bytes_read;
	size_t		i;
}	t_struct;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif