/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <bnoufel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 09:28:37 by bnoufel           #+#    #+#             */
/*   Updated: 2018/02/27 12:16:54 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** @brief change directory to the home
** @param core
** @return [char] home
*/

static char		*change_to_home(t_core *core)
{
	char		*home;

	if (ft_envexist("HOME", core->env))
		home = ft_getenv("HOME", core->env);
	else
	{
		ft_putendl_fd("cd: HOME not set", 2);
		return (NULL);
	}
	return (home);
}

/*
** @brief change dir
** @param [t_core*] core
** @param [char*] dir
*/

static void		ft_change_dir(t_core *core, char *dir)
{
	char		*oldpwd;
	char		*pwd;

	pwd = getcwd(NULL, PATH_MAX);
	if (ft_envexist("OLDPWD", core->env) && pwd)
		ft_setenv(core, ft_strdup("OLDPWD"), pwd);
	else
		free(pwd);
	chdir(dir);
	oldpwd = getcwd(NULL, PATH_MAX);
	if (ft_envexist("PWD", core->env) && oldpwd)
		ft_setenv(core, ft_strdup("PWD"), oldpwd);
	else
		free(oldpwd);
}

/*
** @brief change directory to OLDPWD
** @param core
** @param dir
** @return [int]
*/

static char		*back_to_prev(t_core *core)
{
	char		*dir;

	if (ft_envexist("OLDPWD", core->env))
		dir = ft_getenv("OLDPWD", core->env);
	else
	{
		ft_putendl_fd("cd: OLDPWD not set", 2);
		return (NULL);
	}
	ft_putendl(dir);
	return (dir);
}

/*
** @brief For the norme
** @param dir
** @param core
** @param st
*/

static void		cd_error(char *dir, t_core *core, t_stat st)
{
	if ((dir && access(dir, F_OK) == -1))
	{
		ft_putstr_fd(FOLDER_NOT_FOUND, 2);
		ft_putendl_fd(dir, 2);
	}
	else if (dir && access(dir, R_OK) == -1)
	{
		ft_putstr_fd("cd", 2);
		ft_putstr_fd(MESS_DENIED, 2);
		ft_putendl_fd(dir, 2);
	}
	else if (ft_strcmp(dir, ".") == 0)
		ft_secure_if_is_delete(core, dir);
	else if (dir && !S_ISDIR(st.st_mode))
		ft_putendl_fd("Is not a directory", 2);
	else if (access(dir, F_OK) != -1)
		ft_change_dir(core, dir);
}

/*
** @brief cd command
** @param [t_core*] core
** @return [int]
*/

int				ft_cd(t_core *core)
{
	char		*dir;
	t_stat		st;

	if (!core->arg[1] || ft_strcmp(core->arg[1], "~") == 0)
	{
		if (!(dir = change_to_home(core)))
			return (ERROR);
	}
	else if (ft_strcmp(core->arg[1], "-") == 0)
	{
		if (!(dir = back_to_prev(core)))
			return (ERROR);
	}
	else
		dir = core->arg[1];
	stat(dir, &st);
	if (dir && ft_sstrlen(core->arg) > 2)
		ft_putendl_fd("Too much argument", 2);
	else
		cd_error(dir, core, st);
	return (TRUE);
}
