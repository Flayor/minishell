NAME			= 	minishell

NAMECOLOR 		= 	\x1b[31m
COLOR 			= 	\x1b[36m
COLORFILE		= 	\x1b[35m
COLOROK 		= 	\x1b[32m
COLORRESET 		= 	\x1b[0m

SRCSDIR 		= 	srcs
SRCSDIR1		=	core
SRCSDIR2		=	lst
SRCSDIR3		=	sign
SRCSDIR4		=	builtin

LIBFTDIR 		= 	libft
OBJSDIR 		= 	objects

INCLUDES 		= 	includes
HEADERLIB 		= 	$(LIBFTDIR)/$(INCLUDES)/
HEADER	 		= 	ft_ls.h

DEBUG			=	-g3
CFLAGS 			= 	$(DEBUG) -Wall -Werror -Wextra
LDFLAGS 		= 	-L$(LIBDIR) -lft -ltermcap

CC 				= 	gcc $(CFLAGS)

LIB 			= 	libft.a
LIBDIR 			= 	lib


SRCCORE			=	main.c minishell_core.c ft_error.c ft_color.c ft_free.c
SRCLST			=	create_lst.c count_lst.c delete_lst.c put_lst.c
SRCBUILTIN		=	cd_builtin.c echo_builtin.c env_builtin.c env_builtin2.c \
					env_builtin3.c exit_builtin.c run_cmd.c which_builtin.c
SRCSIGN			=	signal.c


SRCSCORE 		=	$(addprefix $(SRCSDIR1)/, $(SRCCORE))
SRCSLST 		=	$(addprefix $(SRCSDIR2)/, $(SRCLST))
SRCSSIGN		=	$(addprefix $(SRCSDIR3)/, $(SRCSIGN))
SRCSBUILTIN		=	$(addprefix $(SRCSDIR4)/, $(SRCBUILTIN))

SRC 			=	$(SRCSCORE) $(SRCSLST) $(SRCSSIGN) $(SRCSBUILTIN)
OBJ 			= 	$(SRC:%.c=%.o)

SRCS 			= 	$(addprefix $(SRCSDIR)/, $(SRC))
OBJS 			= 	$(addprefix $(OBJSDIR)/, $(OBJ))
HEADERS			= 	$(addprefix $(INCLUDES)/, $(HEADER))

all: $(NAME)

$(NAME): $(LIBFTDIR)/$(LIB) $(OBJSDIR) $(OBJS)
	@$(CC) $(LDFLAGS) -I$(HEADERLIB) $(OBJS) -o $(NAME)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@echo "$(NAMECOLOR)$(NAME): $(COLOR)Compiling: $(COLORFILE)$<...$(COLORRESET)"
	@$(CC) -c -o $@ $< -I$(INCLUDES) -I$(HEADERLIB)

$(OBJSDIR):
	@echo "$(NAMECOLOR)$(NAME): $(COLOR)Create objects dir...$(COLORRESET)";
	@mkdir -p $(OBJSDIR)/$(SRCSDIR1);
	@mkdir -p $(OBJSDIR)/$(SRCSDIR2);
	@mkdir -p $(OBJSDIR)/$(SRCSDIR3);
	@mkdir -p $(OBJSDIR)/$(SRCSDIR4);

$(LIBFTDIR)/$(LIB):
	@make -C $(LIBFTDIR)/
	@make install -C $(LIBFTDIR)/

clean:
	@echo "$(NAMECOLOR)$(NAME): $(COLOR)Removing objects dir...$(COLORRESET)"
	@/bin/rm -rf $(OBJSDIR)
	@make clean -C $(LIBFTDIR)/

fclean: clean
	@echo "$(NAMECOLOR)$(NAME): $(COLOR)Deleting...$(COLORRESET)"
	@/bin/rm -f $(NAME)
	@/bin/rm -rf $(NAME).dSYM
	@make fclean -C $(LIBFTDIR)/

re: fclean all

forbidden:
	@grep -Hn "printf" $(SRCS) || echo "$(COLOROK)no printf function OK$(COLORRESET)"

.PHONY: all, clean, fclean, re, norme, forbidden

.SUFFIXES: .c .o .h
