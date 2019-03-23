# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    lem-in                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybereshc <ybereshc@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:35:04 by ybereshc          #+#    #+#              #
#    Updated: 2018/11/06 19:35:08 by ybereshc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := lem-in
CC := gcc
CFLAGS := -Wall -Wextra -Werror -O3
LIB := lib/
LIBNAME := $(LIB)libft.a
HEADERS := options.h lem_in.h
FILES := main.c print.c options.c parse.c validator.c tools.c bfs.c march.c
OBJS := $(FILES:.c=.o)

all: $(NAME)

$(NAME): mlib $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBNAME) -o $(NAME)
	@echo "\\033[92m$(NAME) was created!\\033[0m"

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

mlib:
	@make -C $(LIB)

clean:
	@make clean -C $(LIB)
	@rm -rf $(OBJS) $(CONST)
	@echo "\\033[91mRemove all $(NAME) objects files.\\033[0m"

fclean:
	@make fclean -C $(LIB)
	@rm -rf $(OBJS) $(CONST) $(NAME)
	@echo "\\033[91mRemove all $(NAME) files.\\033[0m"

re: fclean all

norm:
	@make norm -C $(LIB)
	@norminette $(HEADERS) $(FILES)
