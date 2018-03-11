/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <bnoufel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 07:42:15 by bnoufel           #+#    #+#             */
/*   Updated: 2018/02/27 08:37:58 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** init structure
** @param argc Number of args
** @param argv Lists of args
** @param env environment
** @return
*/

static t_core	*ft_init(int argc, char **argv, char **env)
{
	t_core		*core;
	int			i;
	char		**split;

	i = 0;
	core = create_core_struct();
	core->argv = argv;
	core->argc = argc;
	core->arg = NULL;
	core->env = create_lst();
	while (env[i])
	{
		if (!(split = ft_strsplit(env[i], '=')))
			return (NULL);
		if (!(core->env = pushback(core->env, split[0], split[1], env[i])))
			return (NULL);
		i++;
		ft_free_tab(split);
	}
	return (core);
}

/*
** Parse PATH environment
** @param env evoronment variable
** @return
*/

static char		**ft_parse_path(t_core *core)
{
	char		**parse;
	char		*path;

	if (ft_envexist("PATH", core->env))
	{
		path = ft_getenv("PATH", core->env);
		parse = ft_strsplit(path, ':');
		return (parse);
	}
	else
		return (NULL);
}

/*
** @brief set a env if env -i it's passed
** @param env
** @return [char] env
*/

char			**ft_setenv_if_empty(char **env)
{
	if (ft_sstrlen(env) == 0)
	{
		env[0] = ft_strjoinfree("PWD=", getcwd(NULL, 4096), 2);
		env[1] = 0;
	}
	return (env);
}

/*
** minishell's core
** init big structure
** Read fd 0
** Parse path env
** Split arg
** TODO add parsing to multiple command
** @param argc Number of args
** @param argv Lists of args
** @param env environment
*/

void			minishell(int argc, char **argv, char **env)
{
	t_core		*core;

	signal(SIGINT, signal_handler);
	ft_check_arg(argv);
	env = ft_setenv_if_empty(env);
	core = ft_init(argc, argv, env);
	ft_display_prompt(0);
	while ((core->ret = get_next_line(0, &core->line)))
	{
		g_signal_c = 0;
		core->path = ft_parse_path(core);
		core->arg = ft_split_whitespaces(core->line);
		if (core->arg[0] != '\0' && ft_check_args(core->line) != ERROR)
			ft_run_command(core);
		free(core->line);
		ft_free_tab(core->path);
		ft_free_tab(core->arg);
		if (!g_signal_c)
			ft_display_prompt(0);
	}
	ft_free_list(core->env);
	free(core->line);
	free(core);
}
