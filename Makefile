# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 07:44:13 by vlistrat          #+#    #+#              #
#    Updated: 2016/11/29 08:01:17 by vlistrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS_PATH = ./srcs/

INC = ./includes/

LIBFT_PATH = ./libft/

SRCS_NAME = main.c

SRCS = $(addprefix $(SRCS_PATH),$(SRCS_NAME))

OBJ = $(SRCS:.c=.o)

LIBFT_NAME = -lft

LIBFT = -L$(LIBFT_PATH) $(LIBFT_NAME)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I $(INC)

BL = \x1b[0m
RED = \x1b[31m
HRED = \x1b[1;31m
GREEN = \x1b[31m
HGREEN = \x1b[1;31m
HPURPLE = \x1b[1;34m

all: $(NAME)

$(NAME): $(OBJ)
	@(make -C $(LIBFT_PATH))
	@($(CC) -o $(NAME) $(OBJ))
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
