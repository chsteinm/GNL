/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:23:43 by chrstein          #+#    #+#             */
/*   Updated: 2023/11/30 16:23:47 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	if (dstsize == 0 || !dst)
		return (len);
	i = -1;
	while (++i < dstsize - 1 && src[i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s_len;
	size_t	d_len;

	s_len = 0;
	while (src[s_len])
		s_len++;
	i = 0;
	while (dst[i])
		i++;
	if (size < i || !size)
		return (s_len + size);
	d_len = i;
	while (i < size - 1 && *src)
		dst[i++] = *src++;
	dst[i] = 0;
	return (d_len + s_len);
}

char	*ft_strdup(const char *src)
{
	int		len;
	char	*copy;

	len = ft_strlen(src);
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, src, len + 1);
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * (len));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len);
	ft_strlcat(str, s2, len);
	return (str);
}
