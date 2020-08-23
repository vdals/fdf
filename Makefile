# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnydia <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/15 04:13:08 by jnydia            #+#    #+#              #
#    Updated: 2020/06/15 04:13:14 by jnydia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = ./src
OBJ_DIR = ./obj

INCLUDES = -I libft -I include
LIBS = -L libft -lft -lmlx -framework OpenGL -framework AppKit

SRC = main key drawmap alteration

SRC_C = $(patsubst %, %.c, $(SRC))

OBJS = $(addprefix $(OBJ_DIR)/, $(patsubst %, %.o, $(SRC)))

all: $(NAME)

$(OBJ_DIR):
	mkdir -vp obj

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJS)
		make -C libft
		$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
		/bin/rm -f $(OBJS)
		make clean -C libft/

fclean: clean
		/bin/rm -f $(NAME)
		make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re