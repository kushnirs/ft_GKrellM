# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/02 10:58:17 by skushnir          #+#    #+#              #
#    Updated: 2018/04/14 23:31:42 by skushnir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_gkrellm

CC			= clang++

CFLAGS		= -Wall -Wextra -Werror -g

SRC			= main.cpp UserHostName.cpp TimeData.cpp Info.cpp Cpu.cpp Ram.cpp Network.cpp Graphic.cpp

OBJ			= $(SRC:.cpp=.o)

INCLUDES	= -F./framework
INCLUDES	+= $(addprefix -I, ./framework/SDL2.framework/Headers ./framework/SDL2_ttf.framework/Headers)

FRAMEWORKS	= -rpath ./framework -framework SDL2 -framework SDL2_ttf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INCLUDES) $(FRAMEWORKS) -lncurses 

$(OBJ): %.o : %.cpp
	$(CC) $(CFLAGS) -c $< $(INCLUDES)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.NOTPARALLEL: all $(NAME) re