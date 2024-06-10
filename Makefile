# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 21:09:57 by atorma            #+#    #+#              #
#    Updated: 2024/06/10 14:43:08 by atorma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCE_DIR = source
SOURCES = main.c args.c array.c stack.c move.c record.c chunk.c sort.c cost.c
OBJECTS = $(addprefix $(SOURCE_DIR)/,$(SOURCES:.c=.o))
LIBDIR = ./libft

all: $(NAME)

debug: CFLAGS += -g -fsanitize=address
debug: clean_obj all

$(NAME): $(OBJECTS)
	$(MAKE) -C $(LIBDIR)
	$(CC) -o $@ $(CFLAGS) $^ ./libft/libft.a

$(SOURCE_DIR)/%.o: %.c
	$(CC) -I$(SOURCE_DIR) -c $(CFLAGS) $< -o $@

clean:
	$(MAKE) -C $(LIBDIR) $@
	rm -f $(OBJECTS)

clean_obj:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: debug all clean clean_obj fclean re
