/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <bnoufel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 08:14:47 by bnoufel           #+#    #+#             */
/*   Updated: 2018/02/21 11:32:32 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** @brief exit a program & free
** @param core
*/

void	exit_builtin(t_core *core)
{
	ft_free_tab(core->path);
	ft_free_tab(core->arg);
	free(core->line);
	ft_free_list(core->env);
	exit(1);
}
