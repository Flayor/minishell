/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <bnoufel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:14:02 by bnoufel           #+#    #+#             */
/*   Updated: 2018/02/21 16:34:26 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** @brief Reproduse getenv()
** @param search search a var
** @param env enironment variable
** @return TRUE|FALSE|ERROR
*/

char			*ft_getenv(const char *search, t_env *env)
{
	if (!env || !search)
		return (NULL);
	while (env)
	{
		if (ft_strcmp(env->name, search) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

/*
** @brief set a new arg
** @param core
** @return char*
*/

char			**set_new_arg(t_core *core, int index)
{
	int			i;
	int			j;
	char		**arg;

	i = index;
	j = 0;
	if (!(arg = (char **)malloc(sizeof(char *) * ft_sstrlen(core->arg))))
		return (NULL);
	while (core->arg[i])
	{
		arg[j] = ft_strdup(core->arg[i]);
		i++;
		j++;
	}
	arg[j] = 0;
	return (arg);
}

void			ft_execve(char *cmd, char **arg, char **env, t_core *core)
{
	if (access(cmd, X_OK) != -1)
		execve(cmd, arg, env);
	else
	{
		ft_putstr_fd("minishell", 2);
		ft_putstr_fd(MESS_DENIED, 2);
		ft_putendl_fd(core->arg[0], 2);
	}
}
