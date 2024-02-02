# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 17:27:16 by codespace         #+#    #+#              #
#    Updated: 2024/02/02 17:43:33 by mlopez-i         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

#########
RM = rm -f
CC = cc
CFLAGS = -Werror -Wextra -Wall -g -fsanitize=thread 
#########
FILES = args errors init main threads utils
SRC = $(addsuffix .c, $(FILES))
vpath %.c src
#########
OBJ_DIR = src/obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEP = $(addsuffix .d, $(basename $(OBJ)))
#########


#########

$(OBJ_DIR)/%.o: %.c 
	@mkdir -p $(@D)
	@${CC} $(CFLAGS) -MMD -c $< -o $@

all:
	@$(MAKE) $(NAME) --no-print-directory

$(NAME):: $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "everything done"

clean:
	@$(RM) $(OBJ) $(DEP) --no-print-directory
	@$(RM) -r $(OBJ_DIR) --no-print-directory
	@echo "objects removed"

fclean: clean
	@$(RM) $(NAME) --no-print-directory
	@echo "everything removed"


re:	fclean all

.PHONY: all clean fclean re

-include $(DEP)