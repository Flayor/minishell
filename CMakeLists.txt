cmake_minimum_required(VERSION 3.9)
project(minishell C)

set(CMAKE_C_STANDARD 90)

include_directories("includes")
include_directories("libft/includes")

add_executable(minishell srcs/core/main.c srcs/core/minishell_core.c
srcs/lst/create_lst.c srcs/builtin/run_cmd.c srcs/builtin/env_builtin.c srcs/core/ft_color.c
srcs/builtin/env_builtin.c srcs/builtin/env_builtin2.c srcs/builtin/run_cmd.c srcs/core/ft_color.c
srcs/builtin/cd_builtin.c srcs/builtin/echo_builtin.c srcs/core/ft_error.c
srcs/core/ft_free.c srcs/builtin/which_builtin.c srcs/builtin/exit_builtin.c
srcs/lst/put_lst.c srcs/lst/delete_lst.c srcs/lst/count_lst.c
srcs/builtin/env_builtin2.c srcs/builtin/env_builtin3.c srcs/sign/signal.c)
