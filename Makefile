##
## Makefile for cpp_arcade in /home/pirou_g/ClionProjects/cpp_arcade
## 
## Made by pirou_g
## Login   <pirou_g@epitech.net>
## 
## Started on  Sat Apr  2 14:16:53 2016 pirou_g
## Last update Sun Apr  3 19:00:54 2016 pirou_g
##

CXX		= g++

CC		= gcc

CFLAGS		= -Wall -Wextra -std=gnu11 -I./include -fPIC -c -g

CXXFLAGS	= -Wall -Wextra -std=c++11 -I./include -I./interfaces -I./templates -fPIC -c -g

RM		= rm -rf

SRCS		= src/AEngine.cpp \
		  src/AEvents.cpp \
		  src/Sprites.cpp \
		  src/Map.cpp \
		  src/DL.cpp \
		  src/Entity.cpp \
		  src/MovableEntity.cpp \
		  src/DrawableEntity.cpp

OBJS		= $(SRCS:.cpp=.o)

CSRCS		= src/sprites/pomme.c \
		  src/sprites/snakeGround.c \
		  src/sprites/snakeWall.c \
		  src/sprites/pacman.c \
		  src/sprites/ghost.c \
		  src/sprites/snakeBody.c \
		  src/sprites/pacmanDot.c \
		  src/sprites/pacmanGround.c \
		  src/sprites/pacmanPowerUp.c \
		  src/sprites/pacmanWall.c \
	  	  src/sprites/snakeHead.c

COBJS		= $(CSRCS:.c=.o)

SFML		= libsfmlgui.so

SFML_SRC	= src/SfmlWrapperGui.cpp

SFML_OBJ	= $(SFML_SRC:.cpp=.o)

CACA		= libcacagui.so

CACA_SRC	= src/CacaWrapperGui.cpp

CACA_OBJ	= $(CACA_SRC:.cpp=.o)

OGRE		= libogre.so

OGRE_SRC	= src/OgreWrapper.cpp

OGRE_OBJ	= $(OGRE_SRC:.cpp=.o)

SNAKE		= libarcade_snake.so

SNAKE_SRCS	= $(SRCS) \
		  src/SnakeEngine.cpp \
		  src/Snake.cpp

SNAKE_OBJS	= $(SNAKE_SRCS:.cpp=.o)

PACMAN		= libarcade_pacman.so

PACMAN_SRCS	= $(SRCS) \
		  src/GhostBuster.cpp \
		  src/Pacman.cpp \
		  src/Ghost.cpp

PACMAN_OBJS	= $(PACMAN_SRCS:.cpp=.o)

DL		= cpp_arcade

DL_SRCS		= src/DL.cpp \
		  sfml/main.cpp\
		  src/DLLoader.cpp

DL_OBJS		= $(DL_SRCS:.cpp=.o)

all:		common $(SNAKE) $(PACMAN) $(DL) $(SFML) $(CACA)

common:		$(OBJS) $(COBJS)

$(SFML):	$(SFML_OBJ)
		$(CXX) $(SFML_OBJ) -shared -lsfml-graphics -lsfml-window -lsfml-system -o lib/$(SFML)

$(CACA):	$(CACA_OBJ)
		$(CXX) $(CACA_OBJ) -shared -lcaca -o lib/$(CACA)

$(OGRE):	$(OGRE_OBJ)
		$(CXX) $(OGRE_OBJ) -shared -lOgreOverlay -lOgreMain -lOIS -lboost_system -lpthread -o lib/$(OGRE)

$(SNAKE):	$(SNAKE_OBJS)
		$(CXX) $(SNAKE_OBJS) $(COBJS) -shared -o games/$(SNAKE)

$(PACMAN):	$(PACMAN_OBJS)
		$(CXX) $(PACMAN_OBJS) $(COBJS) -shared -o games/$(PACMAN)

$(DL):		$(DL_OBJS)
		$(CXX) $(DL_OBJS) -ldl -o $(DL)

graphics:	$(SFML) $(CACA)

clean:
		$(RM) $(OBJS) $(COBJS) $(CXXOBJS) $(SFML_OBJS) $(CACA_OBJS) $(SNAKE_OBJS) $(PACMAN_OBJS) $(DL_OBJS)

fclean:		clean
		$(RM) $(SFML) $(CACA) games/$(SNAKE) games/$(PACMAN) $(DL)

re:		fclean all

.PHONY:		all clean fclean re
