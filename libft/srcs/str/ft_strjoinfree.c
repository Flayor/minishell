/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:16:32 by bnoufel           #+#    #+#             */
/*   Updated: 2018/02/20 14:14:24 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strjoinfree(char *s1, char *s2, size_t tofree)
{
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	if (!(new_str = ft_strjoin(s1, s2)))
		return (NULL);
	if (tofree == 1)
		free(s1);
	else if (tofree == 2)
		free(s2);
	else if (tofree == 3)
	{
		free(s1);
		free(s2);
	}
	return (new_str);
}
