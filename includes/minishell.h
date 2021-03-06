/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <bnoufel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:24:49 by bnoufel           #+#    #+#             */
/*   Updated: 2018/02/27 08:11:01 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_MINISHELL_H
# define __MINISHELL_MINISHELL_H
# define RED            "\x1b[31m"
# define GREEN          "\x1b[32m"
# define YELLOW         "\x1b[33m"
# define BLUE           "\x1b[34m"
# define MAGENTA        "\x1b[35m"
# define CYAN           "\x1b[1;36m"
# define BGCYAN         "\x1b[30;46m"
# define PINK           "\x1b[35m"
# define YELLOW         "\x1b[33m"
# define BGYELLOW       "\x1b[30;43m"
# define BGRED          "\x1b[30;41m"
# define RESET          "\x1b[0m"
# define NOT_FOUND		"minishell: command not found: "
# define FOLDER_NOT_FOUND	"cd: no such file or directory: "
# define MESS_FOLDER(f) {ft_putstr_fd(FOLDER_NOT_FOUND, 2);ft_putendl_fd(f, 2);}
# define MESS_DENIED	": permission denied: "
# define TOO_MUCH_ARG	ft_putendl("Too much arguments for setenv")
# define ERROR			-1
# define TRUE			1
# define FALSE			0
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/wait.h>

int					g_signal_c;
typedef struct stat	t_stat;
typedef struct		s_env
{
	char			*name;
	char			*value;
	char			*env;
	struct s_env	*next;
}					t_env;
typedef struct		s_core
{
	int				argc;
	int				ret;
	char			**argv;
	char			**arg;
	char			**path;
	char			*line;
	char			*name_env;
	struct s_env	*env;
}					t_core;
void				minishell(int argc, char **argv, char **env);
void				signal_handler(int sign);
void				catch_signal(void);
t_core				*create_core_struct(void);
void				ft_putcolor(char *color, char *str);
void				ft_display_prompt(int putendl);
void				ft_print_env(t_core *core);
bool				ft_envexist(const char *search, t_env *env);
char				*ft_getenv(const char *search, t_env *env);
bool				ft_setenv(t_core *core, char *name, char *value);
t_env				*ft_unsetenv(t_core *core, char *name);
void				ft_run_command(t_core *core);
int					ft_cd(t_core *core);
void				echo_builtin(t_core *core);
void				ft_check_arg(char **argv);
void				ft_error(int error);
void				ft_free_struct(t_core *core);
void				ft_free_tab(char **tab);
t_env				*ft_create_elem(t_env *lst, char *name, char *value);
char				*test_command(t_core *core, int index);
void				which_builtin(t_core *core);
char				**ft_env_to_tab(t_core *core);
void				ft_free_list(t_env *env);
t_env				*pushback(t_env *lst, char *name, char *value, char *env);
t_env				*ft_delete(t_env *lst, char *name);
void				free_link(t_env *tmp);
void				exit_builtin(t_core *core);
t_env				*create_lst(void);
int					ft_count_list(t_env *env);
void				exec_cmd(t_core *core, char *tmp);
char				**set_new_arg(t_core *core, int index);
void				ft_execve(char *cmd, char **arg, char **env, t_core *core);
void				perm_denied(t_core *core);
void				ft_secure_if_is_delete(t_core *core, char *dir);
int					ft_check_args(char *args);
#endif
