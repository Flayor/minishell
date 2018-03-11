/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <bnoufel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 10:24:19 by bnoufel           #+#    #+#             */
/*   Updated: 2018/02/26 09:59:56 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** @brief env command with arg
** @param core
*/

static void		exec_env_if_arg(t_core *core, int index)
{
	char		*cmd;
	char		**env;
	pid_t		pid;
	char		**arg;

	if ((cmd = test_command(core, index)))
	{
		if (!(arg = set_new_arg(core, index)))
			return ;
		if (!(env = ft_env_to_tab(core)))
			return ;
		pid = fork();
		if (pid > 0)
			wait(0);
		if (pid == 0)
			ft_execve(cmd, arg, env, core);
		free(cmd);
		ft_free_tab(arg);
		ft_free_tab(env);
		cmd = NULL;
	}
}

/*
** @brief env with arg (ex: env ls)
** @param core
*/

static void		ft_env_if_arg(t_core *core)
{
	int			i;
	int			j;

	i = 1;
	j = 1;
	while (core->arg[i])
	{
		if (ft_strcmp(core->arg[i], "-i") == 0)
		{
			ft_putendl_fd("env -i Command not found", 2);
			return ;
		}
		if (ft_strrchr(core->arg[i], '=') != NULL)
			j++;
		i++;
	}
	if (core->arg[j])
		exec_env_if_arg(core, j);
	else
		ft_putendl_fd("usage: env NAME=VALUE cmd", 2);
}

/*
** @brief env command
** @param core
*/

static void		ft_env_without_arg(t_core *core)
{
	t_env		*lst;

	lst = core->env;
	while (lst)
	{
		ft_putendl(lst->env);
		lst = lst->next;
	}
}

/*
** Print the environment variable
** @param env environment variable
*/

void			ft_print_env(t_core *core)
{
	if (core->arg[1])
		ft_env_if_arg(core);
	else if (ft_count_list(core->env) > 0)
		ft_env_without_arg(core);
}

/*
** @param search search a var
** @param env enironment variable
** @return TRUE|FALSE|ERROR
*/

bool			ft_envexist(const char *search, t_env *env)
{
	if (!env || !search)
		return (ERROR);
	while (env)
	{
		if (ft_strcmp(env->name, search) == 0)
			return (TRUE);
		env = env->next;
	}
	return (FALSE);
}
