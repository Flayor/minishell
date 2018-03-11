/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <bnoufel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 07:42:06 by bnoufel           #+#    #+#             */
/*   Updated: 2018/02/21 09:12:02 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_core		*create_core_struct(void)
{
	t_core	*core;

	if (!(core = (t_core *)malloc(sizeof(t_core))))
		return (NULL);
	return (core);
}

t_env		*create_lst(void)
{
	t_env	*lst;

	lst = NULL;
	return (lst);
}
