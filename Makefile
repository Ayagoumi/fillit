# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 16:46:30 by mzaboub           #+#    #+#              #
#    Updated: 2019/07/15 16:27:10 by mzaboub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit

SRC_PATH= .
SRC_NAME=  main.c \
		   check_and_store.c \
		   validation_functions.c \
		   board_functions.c \
		   solve_and_affiche.c
SRC= $(addprefix $(SRC_PATH)/,$(SRC_NAME))


OBJ_PATH= obj
OBJ_NAME= $(SRC_NAME:.c=.o)
OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

LIB_PATH= libft
LIB= libft.a

CC= gcc
CFLAGES= -Wall -Wextra -Werror

LD_FLAGS= -L$(LIB_PATH)
LD_LIBS= -l$(patsubst lib%.a,%, $(LIB))
HDR_FLAGS= -I.




all:$(NAME)

$(NAME): $(LIB_PATH)/$(LIB) $(OBJ)
	@$(CC) $(LD_FLAGS) $(LD_LIBS) $(OBJ) -o $@
	@echo "fillit: executable file is ready ;)"

$(LIB_PATH)/$(LIB):
	@make -C libft 

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(HDR_FLAGS) -o $@ -c $<

clean:
	@rm -fr $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@make -C libft clean
	@echo "fillit: object files deleted"

fclean: clean
	@rm -fr $(NAME)
	@make -C libft fclean
	@echo "fillit: all resources deleted"

re: fclean all

