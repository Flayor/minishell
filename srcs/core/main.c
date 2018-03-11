/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <bnoufel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 07:42:22 by bnoufel           #+#    #+#             */
/*   Updated: 2018/02/20 14:13:19 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** @param putendl add a \n or not
*/

void		ft_display_prompt(int putendl)
{
	char	buff[PATH_MAX + 1];
	char	*cw;
	char	*prompt;

	if (!(cw = getcwd(buff, PATH_MAX)))
		prompt = "my shell";
	ft_putchar('[');
	(cw) ? ft_putcolor(GREEN, cw) : ft_putcolor(GREEN, prompt);
	ft_putchar(']');
	ft_putstr(" $> ");
	if (putendl)
		ft_putchar('\n');
}

/*
** Call minishell
** @param argc Number of args
** @param argv Lists of args
** @param env environment
** @return
*/

int			main(int argc, char **argv, char **env)
{
	minishell(argc, argv, env);
	return (0);
}
