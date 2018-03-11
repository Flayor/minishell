/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <bnoufel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 10:17:38 by bnoufel           #+#    #+#             */
/*   Updated: 2018/02/21 10:20:02 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** @brief count list
** @param [t_env*] env
** @return [int] i
*/

int			ft_count_list(t_env *env)
{
	t_env	*lst;
	int		i;

	i = 0;
	lst = env;
	if (!env)
		return (0);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
