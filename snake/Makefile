CXX	=	g++ -std=c++11

RM	=	rm -f

PRENAME	=	snakeGamePre.a

NAME	=	lib_arcade_snake.so

LIBPIROU	=	../lib/tardis/libtardis.a

SRCDIR	=	../src/

TEMPLATEDIR	=	../templates/

SRCPP	=	$(SRCDIR)AEngine.cpp \
		$(SRCDIR)AEvents.cpp \
		$(SRCDIR)Entity.cpp \
		$(SRCDIR)Map.cpp \
		$(SRCDIR)Snake.cpp \
		$(SRCDIR)DrawableEntity.cpp \
		$(SRCDIR)MovableEntity.cpp \
		$(SRCDIR)SnakeEngine.cpp

SRCC	=	$(SRCDIR)sprites/pomme.c\
		$(SRCDIR)sprites/snakeGround.c\
		$(SRCDIR)sprites/snakeBody.c\
		$(SRCDIR)sprites/snakeHead.c\
		$(SRCDIR)sprites/snakeWall.c

OBJSCPP	=	$(SRCPP:.cpp=.o)

OBJSC	=	$(SRCC:.c=.o)

CXXFLAGS	+=	-Wall -Wextra -g -fPIC

INCFLAGS	=	-I../include
INCFLAGS	+=	-I../interfaces
INCFLAGS	+=	-I../templates
INCFLAGS	+=	-I../lib/tardis/include

CXXFLAGS	+=	$(INCFLAGS)

CFLAGS	=	-Wall -Wextra -Werror $(INCFLAGS)

all:	$(NAME)

$(NAME):	$(OBJSC) $(OBJSCPP)
	ar -rc $(PRENAME) $(OBJSC) $(OBJSCPP)
	gcc -shared -o $(NAME) -Wl,--whole-archive $(PRENAME) -Wl,--no-whole-archive
	mv $(NAME) ../games/

clean:
	$(RM) $(OBJSC) $(OBJSCPP)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
