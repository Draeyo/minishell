# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 07:44:13 by vlistrat          #+#    #+#              #
#    Updated: 2016/11/30 14:59:00 by vlistrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS_PATH = ./srcs/

INC = ./includes/

LIBFT_PATH = ./libft/

SRCS_NAME = main.c get_env.c get_input.c join_path.c utility.c start_process.c \
			prompt_cmd.c ft_error_msh.c ft_exit.c free_all.c

SRCS = $(addprefix $(SRCS_PATH),$(SRCS_NAME))

OBJ = $(SRCS:.c=.o)

LIBFT_NAME = -lft

LIBFT = -L$(LIBFT_PATH) $(LIBFT_NAME)

CC = gcc

CFLAGS_REL = -Wall -Werror -Wextra -I $(INC)

CFLAGS = -I $(INC)

BL = \x1b[0m
RED = \x1b[31m
HRED = \x1b[1;31m
GREEN = \x1b[31m
HGREEN = \x1b[1;31m
HPURPLE = \x1b[1;34m

all: $(NAME)

$(NAME): $(OBJ)
	@(make -C $(LIBFT_PATH))
	@($(CC) -o $(NAME) $(OBJ) $(LIBFT))
	@(echo "$(HPURPLE)$(NAME)$(BL) $(GREEN)created.$(BL) $(HGREEN)✓$(BL)")

%.o: %.c
	@($(CC) -o $@ -c $< $(CFLAGS))

clean:
	@(make -C $(LIBFT_PATH) clean)
	@(/bin/rm -f $(OBJ))
	@(echo "$(HPURPLE)$(NAME)$(BL) object files $(RED)deleted.$(BL) $(HGREEN)✓$(BL)")

fclean: clean
	@(make -C $(LIBFT_PATH) fclean)
	@(/bin/rm -f $(NAME))
	@(echo "$(HPURPLE)$(NAME)$(BL) $(RED)deleted.$(BL) $(HGREEN)✓$(BL)")

re: fclean all
