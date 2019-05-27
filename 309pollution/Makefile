##
## EPITECH PROJECT, 2018
## 304pacman
## File description:
## makefile
##

CXX			=	g++

RM			=	rm -f

SRC			=	src/

SRCS		=	$(SRC)main.cpp		\
				$(SRC)Pollution.cpp

OBJS		=	$(SRCS:.cpp=.o)

NAME		=	309pollution

CPPFLAGS	= -I./include -Wall -Wextra -Werror -std=c++14

all: $(NAME)

$(NAME):	$(OBJS)
		$(CXX) $(OBJS) -o $(NAME) $(CPPFLAGS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re