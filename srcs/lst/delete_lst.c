/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <bnoufel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 08:46:39 by bnoufel           #+#    #+#             */
/*   Updated: 2018/02/24 07:45:08 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** @brief delete a link
** @param lst
** @param name
** @return
*/

t_env		*ft_delete(t_env *lst, char *name)
{
	t_env	*tmp;
	t_env	*prev;

	if (!lst)
		return (lst);
	prev = lst;
	if (ft_strcmp(prev->name, name) == 0)
	{
		lst = prev->next;
		free_link(prev);
		return (lst);
	}
	tmp = prev->next;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			prev->next = tmp->next;
			free_link(tmp);
			return (lst);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (lst);
}
