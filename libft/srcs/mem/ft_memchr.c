/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:51:32 by bnoufel           #+#    #+#             */
/*   Updated: 2018/02/20 14:14:24 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p_s;

	i = 0;
	p_s = (unsigned char *)s;
	while (i < n)
	{
		if (p_s[i] == (unsigned char)c)
			return ((p_s + i));
		i++;
	}
	return (NULL);
}
