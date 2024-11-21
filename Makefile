# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thiew <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 12:56:21 by thiew             #+#    #+#              #
#    Updated: 2024/05/07 14:19:15 by tjuvan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror 
NAME = push_swap
SRC_FILES = push_swap.c make_list.c fuck_norminette.c fft_split.c merge_sort.c sorting_comms.c algo.c algo2.c \
			print_comms.c di_finder.c push_utils.c soft_landing.c medium_sort.c

OBJ_FILES = $(SRC_FILES:%.c=%.o)

all: $(NAME) 

$(NAME): $(OBJ_FILES)
	$(MAKE) -C ./final_libft
	$(CC) $(CFLAGS) $(OBJ_FILES) ./final_libft/libft.a -o $(NAME) $(size)

clean:
	$(MAKE) -C ./final_libft fclean
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

