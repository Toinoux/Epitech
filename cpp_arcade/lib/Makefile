##
## EPITECH PROJECT, 2018
## makefile
## File description:
## nothing
##

CC		=	g++

SFML_NAME	=	lib_arcade_sfml.so

NCURSES_NAME	=	lib_arcade_ncurses.so

SDL2_NAME	=	lib_arcade_sdl2.so

RM		=       rm -rf

CFLAGS		+=	-W -Wextra -Wall

CFLAGS		+=	-I ../inc/

CFLAGS		+=	 -std=c++14 -fPIC

LDFLAGS		=	-ldl

LIB_DIR		=	.

SFML_SRCS	=	sfml/ArcadeSFML.cpp\
			sfml/getInstance.cpp

SFML_SRCS	:=	$(addprefix $(LIB_DIR)/, $(SFML_SRCS))

SFML_OBJS	=	$(SFML_SRCS:.cpp=.o)

SDL2_SRCS	=	sdl2/ArcadeSDL2.cpp\
			sdl2/getInstance.cpp

SDL2_SRCS	:=	$(addprefix $(LIB_DIR)/, $(SDL2_SRCS))

SDL2_OBJS	=	$(SDL2_SRCS:.cpp=.o)

NCURSES_SRCS	=	ncurses/ArcadeNcurses.cpp\
			ncurses/getInstance.cpp

NCURSES_SRCS	:=	$(addprefix $(LIB_DIR)/, $(NCURSES_SRCS))

NCURSES_OBJS	=	$(NCURSES_SRCS:.cpp=.o)

%.o: %.cpp
		@printf "[\033[0;32mdone\033[0m] % 33s\n" $<
		@$(CC) -c -o $@ $< $(CFLAGS)

all:	$(SFML_NAME) $(NCURSES_NAME) $(SDL2_NAME)

$(SFML_NAME):	$(SFML_OBJS)
		$(CC) -o $(LIB_DIR)/$(SFML_NAME) $(SFML_OBJS) -shared -lsfml-system -lsfml-graphics -lsfml-window

$(NCURSES_NAME):	$(NCURSES_OBJS)
		$(CC) -o $(LIB_DIR)/$(NCURSES_NAME) $(NCURSES_OBJS) -shared -lncurses

$(SDL2_NAME):	$(SDL2_OBJS)
		$(CC) -o $(LIB_DIR)/$(SDL2_NAME) $(SDL2_OBJS) -shared -lSDL2 -lSDL2_ttf -lSDL2_image

clean:
		$(RM) $(SDL2_OBJS)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(SDL2_OBJS)
		$(RM) $(NCURSES_OBJS)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(NCURSES_OBJS)
		$(RM) $(SFML_OBJS)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(SFML_OBJS)

fclean:         clean
		$(RM) $(LIB_DIR)/$(SFML_NAME)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(SFML_NAME)
		$(RM) $(LIB_DIR)/$(NCURSES_NAME)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(NCURSES_NAME)
		$(RM) $(LIB_DIR)/$(SDL2_NAME)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(SDL2_NAME)

re:             fclean all

.PHONY:         all clean fclean re