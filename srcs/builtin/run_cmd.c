/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <bnoufel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 06:23:13 by bnoufel           #+#    #+#             */
/*   Updated: 2018/02/27 07:56:55 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Test with all path if bin exist
** @param core big struct
** @return
*/

char			*test_command(t_core *core, int index)
{
	int			i;
	char		*tmp;
	char		*to_free;

	i = -1;
	if (!core->path && (tmp = ft_strdup(core->arg[index])))
	{
		if (access(tmp, F_OK) != -1)
			return (tmp);
		free(tmp);
	}
	while (core->path && core->path[++i])
	{
		if (!ft_strchr(core->arg[index], '/'))
		{
			to_free = ft_strjoin(core->path[i], "/");
			tmp = ft_strjoinfree(to_free, core->arg[index], 1);
		}
		else
			tmp = ft_strdup(core->arg[index]);
		if (access(tmp, F_OK) != -1)
			return (tmp);
		free(tmp);
	}
	return (NULL);
}

/*
** @brief Check if arg is valid
** @param [t_core*] core
** @return int
*/

static int		ft_arg_is_valid(t_core *core)
{
	if (!core->arg[1])
		return (5);
	else if (ft_strindexchr(core->arg[1], '=') == 0)
		return (2);
	else if (ft_strcountoccur(core->arg[1], '=') > 1)
		return (3);
	else
		return (TRUE);
}

/*
** @brief Check n add env
** @param core
*/

void			ft_check_setenv(t_core *core)
{
	char		**tmp;

	if (ft_sstrlen(core->arg) == 2 && ft_arg_is_valid(core) == 1)
	{
		tmp = ft_strsplit(core->arg[1], '=');
		if (tmp[1])
			ft_setenv(core, tmp[0], tmp[1]);
		else
			ft_setenv(core, tmp[0], ft_strdup(""));
		free(tmp);
	}
	else
		ft_error(ft_arg_is_valid(core));
}

/*
** @brief exec a command
** @param [t_core*] core
** @param [char*] tmp
*/

void			exec_cmd(t_core *core, char *tmp)
{
	char		**env;
	pid_t		pid;
	t_stat		st;

	if (!(env = ft_env_to_tab(core)))
		return ;
	lstat(tmp, &st);
	if (S_ISDIR(st.st_mode) || !(st.st_mode & S_IXUSR))
		ft_putendl_fd("Not a binary", 2);
	else
	{
		pid = fork();
		(pid > 0) ? wait(0) : 0;
		if (pid == 0)
		{
			if (access(tmp, X_OK) != -1)
				((execve(tmp, core->arg, env)) == -1) ? exit(1) : 1;
			else
				perm_denied(core);
		}
	}
	free(tmp);
	ft_free_tab(env);
	tmp = NULL;
}

/*
** compare arg for execute the command
** echo, cd, exit, env, setenv, unsetenv
** @param pid
** @param core
** @param env
*/

void			ft_run_command(t_core *core)
{
	char		*tmp;

	if (ft_strcmp(core->arg[0], "env") == 0)
		ft_print_env(core);
	else if (ft_strcmp(core->arg[0], "setenv") == 0)
		ft_check_setenv(core);
	else if (ft_strcmp(core->arg[0], "unsetenv") == 0)
		(core->arg[1]) ? core->env = ft_unsetenv(core, core->arg[1]) : 0;
	else if (ft_strcmp(core->arg[0], "cd") == 0)
		ft_cd(core);
	else if (ft_strcmp(core->arg[0], "echo") == 0)
		echo_builtin(core);
	else if (ft_strcmp(core->arg[0], "which") == 0)
		which_builtin(core);
	else if (ft_strcmp(core->arg[0], "exit") == 0)
		exit_builtin(core);
	else if ((tmp = test_command(core, 0)) != NULL)
		exec_cmd(core, tmp);
	else
	{
		ft_putstr_fd(NOT_FOUND, 2);
		ft_putendl_fd(core->arg[0], 2);
	}
}
