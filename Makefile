# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 21:09:57 by atorma            #+#    #+#              #
#    Updated: 2024/06/10 21:06:41 by atorma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCE_DIR = source
SOURCES = main.c args.c array.c stack.c move.c record.c chunk.c sort.c cost.c
OBJECTS = $(addprefix $(SOURCE_DIR)/,$(SOURCES:.c=.o))
LIBDIR = ./libft

target debug: CFLAGS += -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C $(LIBDIR)
	$(CC) -o $@ $(CFLAGS) $^ ./libft/libft.a

$(SOURCE_DIR)/%.o: %.c
	$(CC) -I$(SOURCE_DIR) -c $(CFLAGS) $< -o $@

clean:
	$(MAKE) -C $(LIBDIR) $@
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: re

.PHONY: debug all clean fclean re
