/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <bstrong@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:42:44 by bstrong           #+#    #+#             */
/*   Updated: 2021/10/27 20:42:44 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(char *dest, const char *src, size_t n)
{
	char	*destaddr;

	if (!n || dest == src)
		return (dest);
	destaddr = dest;
	while (n--)
		*destaddr++ = *src++;
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	int	size;

	size = 0;
	while (str && str[size])
		++size;
	return (size);
}

size_t	ft_strlcpy(char *dest, const char *str, size_t size)
{
	size_t	strlen;

	strlen = ft_strlen(str);
	if (strlen + 1 < size)
		ft_memcpy(dest, str, strlen + 1);
	else if (size != 0)
	{
		ft_memcpy(dest, str, size - 1);
		dest[size - 1] = '\0';
	}
	return (strlen);
}

char	*ft_strdup(char *s, char *del)
{
	size_t	size;
	char	*dest;

	size = ft_strlen(s) + 1;
	dest = (char *)malloc(size);
	if (!dest || !s || size == 1)
	{
		free (del);
		free(dest);
		return (NULL);
	}
	ft_memcpy(dest, s, size);
	free(del);
	return (dest);
}

char	*ft_strchr(const char *str, int ch)
{
	char	*temp;

	if (!str)
		return (NULL);
	temp = (char *)str;
	while (*temp != (unsigned char)ch)
	{
		if (*temp == 0)
			return (NULL);
		++temp;
	}
	return (temp);
}
