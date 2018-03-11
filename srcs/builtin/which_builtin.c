/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <bnoufel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 06:20:38 by bnoufel           #+#    #+#             */
/*   Updated: 2018/02/24 09:55:00 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void		which_builtin(t_core *core)
{
	char	*cmd;

	if (!core->arg[1])
		ft_putendl_fd("usage: which \"program\"", 2);
	else if (ft_strcmp(core->arg[1], "which") == 0 || \
	ft_strcmp(core->arg[1], "echo") == 0 || \
	ft_strcmp(core->arg[1], "cd") == 0 ||\
	ft_strcmp(core->arg[1], "exit") == 0 ||\
	ft_strcmp(core->arg[1], "env") == 0 ||\
	ft_strcmp(core->arg[1], "setenv") == 0 ||\
	ft_strcmp(core->arg[1], "unsetenv") == 0)
	{
		ft_putstr(core->arg[1]);
		ft_putendl(": shell built-in command");
	}
	else if ((cmd = test_command(core, 1)))
	{
		ft_putendl(cmd);
		free(cmd);
	}
}
