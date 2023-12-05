/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:23:25 by chrstein          #+#    #+#             */
/*   Updated: 2023/11/30 16:23:29 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	is_backn(t_struct *strct, int fd)
{
	if (strct->buf_ptr[fd])
		while (*strct->buf_ptr[fd])
			if (*strct->buf_ptr[fd]++ == '\n')
				return (1);
	return (0);
}

char	*ret_line(t_struct *strct, int fd)
{
	int	index;

	index = 0;
	if (!strct->tmp[fd])
		return (NULL);
	while (strct->tmp[fd][index] != '\n')
		index++;
	strct->tmp[fd][index + 1] = 0;
	return (strct->tmp[fd]);
}

char	*read_and_ret(t_struct *strct, int fd)
{
	strct->buf_ptr[fd] = strct->buf[fd];
	strct->bytes_read[fd] = read(fd, strct->buf[fd], BUFFER_SIZE);
	if (!strct->bytes_read[fd] || !strct->buf[fd][0])
		return (0);
	if (strct->bytes_read[fd] == -1)
		return (free(strct->tmp[fd]), strct->tmp[fd] = 0);
	strct->buf[fd][strct->bytes_read[fd]] = 0;
	strct->tmp_tmp = strct->tmp[fd];
	if (strct->tmp[fd])
		strct->tmp[fd] = ft_strjoin(strct->tmp[fd], strct->buf[fd]);
	else
		strct->tmp[fd] = ft_strdup(strct->buf[fd]);
	free(strct->tmp_tmp);
	if (!strct->tmp[fd])
		return (0);
	return (strct->tmp[fd]);
}

char	*get_next_line(int fd)
{
	static t_struct	strct;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (strct.bytes_read[fd] < 1)
	{
		strct.tmp[fd] = NULL;
		strct.buf_ptr[fd] = NULL;
	}
	else
		strct.tmp[fd] = ft_strdup(strct.buf_ptr[fd]);
	if (is_backn(&strct, fd))
		return (ret_line(&strct, fd));
	while (read_and_ret(&strct, fd))
		if (is_backn(&strct, fd))
			return (ret_line(&strct, fd));
	if (strct.bytes_read[fd] == -1)
		*strct.buf_ptr[fd] = 0;
	if (strct.tmp[fd] && !strct.tmp[fd][0])
		return (free(strct.tmp[fd]), NULL);
	return (strct.tmp[fd]);
}
