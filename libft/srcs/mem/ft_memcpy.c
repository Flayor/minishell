/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:32:23 by bnoufel           #+#    #+#             */
/*   Updated: 2018/02/20 14:14:24 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p_dst;
	unsigned char	*p_src;

	i = 0;
	p_dst = (unsigned char*)dst;
	p_src = (unsigned char*)src;
	while (i < n)
	{
		p_dst[i] = p_src[i];
		i++;
	}
	return (dst);
}
