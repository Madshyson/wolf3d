#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguillot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/29 20:50:24 by tguillot          #+#    #+#              #
#    Updated: 2016/06/06 14:10:15 by mlavanan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

SRC = 	main.c \
		ft_keyfunct.c \
		get_color.c \
		put_pixel_to_img.c \
		draw_vertline.c \
		raycast.c \
		wolf_test_map.c \
		wolf_get_map.c \
		ft_mouse_func.c \
		ft_error.c \

OBJ = 	main.o \
		ft_keyfunct.o \
		get_color.o \
		put_pixel_to_img.o \
		draw_vertline.o \
		raycast.o \
		wolf_test_map.o \
		wolf_get_map.o \
		ft_mouse_func.o \
		ft_error.o \

HEADER = wolf.h\
		./libft/libft.h\

FINDLIBFT = -Llibft

LIBFTA = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror 

LIBFT_DIR = ./libft/

all: $(NAME)

$(NAME):
	@clear
	@echo "\033[35;4mRule all!\033[0m"
	@make fclean -C $(LIBFT_DIR)
	@make -C $(LIBFT_DIR)
	@gcc $(FLAGS) -c $(SRC) $(HEADER)
	@gcc -o $(NAME) $(OBJ) $(LIBFTA) -lmlx -framework OpenGL -framework AppKit 

clean:
	@clear
	@echo "\033[35;4mRule clean!\033[0m"
	@rm -f $(OBJ)
	@rm -f wolf.h.gch
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@clear
	@echo "\033[35;4mRule fclean!\033[0m"
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
	@clear
	@echo "\033[35;4mRules fclean and all!\033[0m"

.PHONY: all, clean, fclean, re