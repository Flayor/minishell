/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <bnoufel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 08:43:50 by bnoufel           #+#    #+#             */
/*   Updated: 2018/02/21 09:12:56 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** @brief put a link to a list to the head
** @param lst
** @param name
** @param value
** @return
*/

t_env		*ft_create_elem(t_env *lst, char *name, char *value)
{
	t_env	*tmp;

	if (!(tmp = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	tmp->name = ft_strdup(name);
	tmp->value = ft_strdup(value);
	tmp->next = lst;
	return (tmp);
}

/*
** @brief put a link to a list to the end
** @param lst
** @param name
** @param value
** @param env
** @return
*/

t_env		*pushback(t_env *lst, char *name, char *value, char *env)
{
	t_env	*tmp;
	t_env	*new;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	new->name = (name) ? ft_strdup(name) : ft_strdup("");
	new->value = (value) ? ft_strdup(value) : ft_strdup("");
	new->env = ft_strdup(env);
	new->next = NULL;
	if (!lst)
		return (new);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (lst);
}
