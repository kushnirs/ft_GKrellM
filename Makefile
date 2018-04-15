# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/02 10:58:17 by skushnir          #+#    #+#              #
#    Updated: 2018/04/15 19:51:45 by skushnir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_gkrellm

CC			= clang++

CFLAGS		= -Wall -Wextra -Werror

SRC			= main.cpp UserHostName.cpp TimeData.cpp Info.cpp Cpu.cpp Ram.cpp Network.cpp Graphic.cpp Gkrellm.cpp

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