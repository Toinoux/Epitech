##
## EPITECH PROJECT, 2018
## makefile
## File description:
## nothing
##

CC		=	g++

NAME		=	arcade

SFML_NAME	=	lib_arcade_sfml.so

NCURSES_NAME	=	lib_arcade_ncurses.so

SDL2_NAME	=	lib_arcade_sdl2.so

SNAKE_NAME	=	lib_arcade_nibbler.so

SOLARFOX_NAME	=	lib_arcade_solarfox.so

CENTIPEDE_NAME	=	lib_arcade_centipede.so

RM		=       rm -rf

CFLAGS		+=	-W -Wextra -Wall

CFLAGS		+=	-I inc/

CFLAGS		+=	 -std=c++14 -fPIC

LDFLAGS		=	-ldl

LIB_DIR		=	lib

GAME_DIR	=	game

GAMES_DIR	=	games

SRC_DIR		=	src

SRCS		=       main.cpp\
			Utilities.cpp\
			Screen.cpp\
			Arcade.cpp\
			Game.cpp\

SRCS		:=	$(addprefix $(SRC_DIR)/, $(SRCS))

OBJS		=	$(SRCS:.cpp=.o)

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

SNAKE_SRCS	=	snake/ArcadeSnake.cpp\
			../src/Game.cpp\
			../src/Utilities.cpp\
			snake/getInstance.cpp

SNAKE_SRCS	:=	$(addprefix $(GAME_DIR)/, $(SNAKE_SRCS))

SNAKE_OBJS	=	$(SNAKE_SRCS:.cpp=.o)

SOLARFOX_SRCS	=	solarfox/ArcadeSolarFox.cpp\
			../src/Game.cpp\
			../src/Utilities.cpp\
			solarfox/getInstance.cpp

SOLARFOX_SRCS	:=	$(addprefix $(GAME_DIR)/, $(SOLARFOX_SRCS))

SOLARFOX_OBJS	=	$(SOLARFOX_SRCS:.cpp=.o)

CENTIPEDE_SRCS	=	centipede/ArcadeCentipede.cpp\
			../src/Game.cpp\
			../src/Utilities.cpp\
			centipede/getInstance.cpp

CENTIPEDE_SRCS	:=	$(addprefix $(GAME_DIR)/, $(CENTIPEDE_SRCS))

CENTIPEDE_OBJS	=	$(CENTIPEDE_SRCS:.cpp=.o)

%.o: %.cpp
		@printf "[\033[0;32mdone\033[0m] % 33s\n" $<
		@$(CC) -c -o $@ $< $(CFLAGS)

all:            core games graphicals

core:		$(NAME)

games:		$(SNAKE_NAME) $(SOLARFOX_NAME) $(CENTIPEDE_NAME)

graphicals:	$(SFML_NAME) $(NCURSES_NAME) $(SDL2_NAME)

$(NAME):        $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

$(SFML_NAME):	$(SFML_OBJS)
		$(CC) -o $(LIB_DIR)/$(SFML_NAME) $(SFML_OBJS) -shared -lsfml-system -lsfml-graphics -lsfml-window

$(NCURSES_NAME):	$(NCURSES_OBJS)
		$(CC) -o $(LIB_DIR)/$(NCURSES_NAME) $(NCURSES_OBJS) -shared -lncurses

$(SDL2_NAME):	$(SDL2_OBJS)
		$(CC) -o $(LIB_DIR)/$(SDL2_NAME) $(SDL2_OBJS) -shared -lSDL2 -lSDL2_ttf -lSDL2_image

$(SNAKE_NAME):	$(SNAKE_OBJS)
		$(CC) -o $(GAMES_DIR)/$(SNAKE_NAME) $(SNAKE_OBJS) -shared

$(SOLARFOX_NAME):	$(SOLARFOX_OBJS)
		$(CC) -o $(GAMES_DIR)/$(SOLARFOX_NAME) $(SOLARFOX_OBJS) -shared

$(CENTIPEDE_NAME):$(CENTIPEDE_OBJS)
		$(CC) -o $(GAMES_DIR)/$(CENTIPEDE_NAME) $(CENTIPEDE_OBJS) -shared

clean:
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJS)
		$(RM) $(OBJS)
		$(RM) $(SDL2_OBJS)
		$(RM) $(NCURSES_OBJS)
		$(RM) $(SFML_OBJS)
		$(RM) $(SNAKE_OBJS)
		$(RM) $(SOLARFOX_OBJS)
		$(RM) $(CENTIPEDE_OBJS)

fclean:         clean
		$(RM) $(NAME)
		$(RM) $(LIB_DIR)/$(SFML_NAME)
		$(RM) $(LIB_DIR)/$(NCURSES_NAME)
		$(RM) $(LIB_DIR)/$(SDL2_NAME)
		$(RM) $(GAMES_DIR)/$(SNAKE_NAME)
		$(RM) $(GAMES_DIR)/$(SOLARFOX_NAME)
		$(RM) $(GAMES_DIR)/$(CENTIPEDE_NAME)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(NAME)

re:             fclean all

.PHONY:         all clean fclean re
