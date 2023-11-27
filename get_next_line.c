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

char    *ret_line(t_struct *strct)
{
    int     len;
    char    *line;

    len = 0;
    while (strct->tmp[len] && strct->tmp[len] != '\n')
        len++;
    line = malloc(len + 2);
    ft_strlcpy(line, strct->tmp, len + 2);
    strct->tmp += len + 1;
    return (line);
}

char    *read_and_ret(t_struct *strct, int fd)
{
    strct->bytes_read = read(fd, strct->buf, BUFFER_SIZE);
    if (strct->bytes_read < 1)
        return (0);
    strct->buf[strct->bytes_read] = 0;
    strct->tmp_tmp = strct->tmp;
    if (strct->tmp)
        strct->tmp = ft_strjoin(strct->tmp, strct->buf);
    else
        strct->tmp = ft_strdup(strct->buf);
    // if (strct->tmp_tmp != NULL)
    //     free(strct->tmp_tmp);
    if (!strct->tmp)
        return (0);
    return (strct->tmp);
}

char	*get_next_line(int fd)
{
    static t_struct strct;

    if (fd < 0)
        return (0);
    if (strct.bytes_read == 0)
        strct.tmp = NULL;
    if (is_backn(strct.tmp))
        return (ret_line(&strct));
    while (read_and_ret(&strct, fd))
    {
        if (is_backn(strct.tmp))
            return (ret_line(&strct));
    }
    return (strct.tmp);
}