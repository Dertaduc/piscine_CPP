# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 17:32:34 by candre--          #+#    #+#              #
#    Updated: 2025/12/06 15:21:42 by candre--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRC = megaphone.cpp
OBJ = $(addprefix build/, $(SRC:.cpp=.o))
CPP = c++
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98


all : $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPP_FLAGS) $(SRC) -o $(NAME)

build/%.o: %.cpp
	@mkdir -p build/
	@$(CPP) $(CPP_FLAGS) -c $< -o $@

clean :
	rm -rf build

fclean :
	rm -rf build
	rm -rf $(NAME)

re :
	$(MAKE) fclean;
	$(MAKE) all;