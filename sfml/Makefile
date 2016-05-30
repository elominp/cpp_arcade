##
## Makefile for tek2 in /home/pyre/projet/tek2/PSU/PSU_2015_lemipc
##
## Made by pyre
## Login   <pyre@epitech.net>
##
## Started on  Tue Mar 22 09:21:23 2016 pyre
## Last update Fri Mar 25 11:06:13 2016
##

CXX	= g++ -std=c++11

RM	= rm -f

NAME	= sfml-test

SRCCPP	= 	../src/SfmlWrapperGui.cpp\
		../src/AEvents.cpp\
		main.cpp\
		../src/CacaWrapperGui.cpp

SRCC	=		../src/sprites/pomme.c\
		../src/sprites/snakeGround.c\
		../src/sprites/snakeWall.c

OBJSCPP	= $(SRCCPP:.cpp=.o)

OBJSC	= $(SRCC:.c=.o)

CXXFLAGS	+=  -Wall -Wextra -g

INCFLAGS = -I../include
INCFLAGS += -I../interfaces
INCFLAGS += -I../templates

CXXFLAGS	+= $(INCFLAGS)

CFLAGS	= -Wall -Wextra -Werror $(INCFLAGS)

all:	$(NAME)

$(NAME):	$(OBJSC) $(OBJSCPP)
	$(CXX) -o $(NAME) $(OBJSC) $(OBJSCPP) -lsfml-graphics -lsfml-window -lsfml-system -lcaca

clean:
	$(RM) $(OBJSCPP) $(OBJSC)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
