# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/06 15:36:33 by candre--          #+#    #+#              #
#    Updated: 2026/01/03 20:10:46 by candre--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = polymorph

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
OBJ_DIR = build
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
DEP = $(OBJ:.o=.d)

CPP = c++
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP

all : $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPP_FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CPP) $(CPP_FLAGS) -c $< -o $@

-include $(DEP)

clean :
	@rm -rf $(OBJ_DIR)

fclean :
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)

re :
	@$(MAKE) --no-print-directory fclean;
	@$(MAKE) --no-print-directory all;

.PHONY: all clean fclean re