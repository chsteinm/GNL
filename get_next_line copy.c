/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:06:19 by chrstein          #+#    #+#             */
/*   Updated: 2023/11/20 20:06:21 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     is_backn(char *str)
{
    if (str)
        while (*str)
            if (*str++ == '\n')
                return (1);   
    return (0);
}

char    *ret_line(char **stash)
{
    int     len;
    char    *line;

    len = 0;
    while (*stash[len] != '\n')
        len++;
    line = malloc(len + 2);
    ft_strlcpy(line, *stash, len + 2);
    free(*stash);
    *stash += len + 1;
    return (line);
}

char    *read_and_ret(t_struct *strct, int fd)
{
    strct->bytes_read = read(fd, strct->buf, BUFFER_SIZE);
    if (strct->bytes_read < 1)
        return (0);
    strct->buf[strct->bytes_read] = 0;
    strct->tmp_tmp = strct->stash;
    if (strct->stash)
        strct->stash = ft_strjoin(strct->stash, strct->buf);
    else
        strct->stash = ft_strdup(strct->buf);
    if (strct->tmp_tmp != NULL)
        free(strct->tmp_tmp);
    if (!strct->stash)
        return (0);
    return (strct->stash);
}

char	*get_next_line(int fd)
{
    char        buf[BUFFER_SIZE + 1];
    static char *stash;
    char        *stash_tmp;
    ssize_t     bytes_read;

    if (fd < 0)
        return (0);
    // if (strct.bytes_read == 0)
    //     strct.stash = NULL;
    if (is_backn(stash))
        return (ret_line(&stash));
    while (read_and_ret(&strct, fd))
    {
        if (is_backn(stash))
            return (ret_line(&stash));
    }
    return (strct.stash);
}
