# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 21:09:57 by atorma            #+#    #+#              #
#    Updated: 2024/05/22 21:38:47 by atorma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCE_DIR = source
SOURCES = main.c args.c
OBJECTS = $(addprefix $(SOURCE_DIR)/,$(SOURCES:.c=.o))
LIBDIR = ./libft

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

.PHONY: all clean fclean re
