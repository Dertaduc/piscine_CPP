# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/06 15:36:33 by candre--          #+#    #+#              #
#    Updated: 2025/12/09 15:42:28 by candre--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRC = main.cpp Contact.cpp Phonebook.cpp
OBJ = $(addprefix build/, $(SRC:.cpp=.o))
CPP = c++
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98


all : $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPP_FLAGS) $(OBJ) -o $(NAME)

build/%.o: %.cpp
	@mkdir -p build/
	@$(CPP) $(CPP_FLAGS) -c $< -o $@

clean :
	@rm -rf build

fclean :
	@rm -rf build
	@rm -rf $(NAME)

re :
	@$(MAKE) --no-print-directory fclean;
	@$(MAKE) --no-print-directory all;

.PHONY: all clean fclean re