/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <bnoufel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 09:34:46 by bnoufel           #+#    #+#             */
/*   Updated: 2018/02/21 09:35:06 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** @brief echo -n command
** @param [t_core*] core
*/

static void		ft_echo_n(t_core *core)
{
	int			i;

	i = 2;
	while (core->arg[i])
	{
		ft_putstr(core->arg[i]);
		(core->arg[i + 1]) ? ft_putchar(' ') : 0;
		i++;
	}
}

/*
** @brief echo command
** @param [t_core*] core
*/

static void		ft_echo(t_core *core)
{
	int			i;

	i = 1;
	while (core->arg[i])
	{
		ft_putstr(core->arg[i]);
		(core->arg[i + 1]) ? ft_putchar(' ') : ft_putstr("\n");
		i++;
	}
}

/*
** @brief echo command
** @param core
*/

void			echo_builtin(t_core *core)
{
	if (!core->arg[1])
		ft_putchar('\n');
	else if (!core->arg[2] && ft_strcmp(core->arg[1], "-n") == 0)
		return ;
	else if (ft_strcmp(core->arg[1], "-n") == 0)
		ft_echo_n(core);
	else
		ft_echo(core);
}
