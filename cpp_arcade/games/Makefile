##
## EPITECH PROJECT, 2018
## makefile
## File description:
## nothing
##

CC		=	g++

SNAKE_NAME	=	lib_arcade_nibbler.so

SOLARFOX_NAME	=	lib_arcade_solarfox.so

CENTIPEDE_NAME	=	lib_arcade_centipede.so

RM		=       rm -rf

CFLAGS		+=	-W -Wextra -Wall

CFLAGS		+=	-I ../inc/

CFLAGS		+=	 -std=c++14 -fPIC

LDFLAGS		=	-ldl

GAME_DIR	=	../game

GAMES_DIR	=	.

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

all:		$(SNAKE_NAME) $(SOLARFOX_NAME) $(CENTIPEDE_NAME)

$(SNAKE_NAME):	$(SNAKE_OBJS)
		$(CC) -o $(GAMES_DIR)/$(SNAKE_NAME) $(SNAKE_OBJS) -shared

$(SOLARFOX_NAME):	$(SOLARFOX_OBJS)
		$(CC) -o $(GAMES_DIR)/$(SOLARFOX_NAME) $(SOLARFOX_OBJS) -shared

$(CENTIPEDE_NAME):$(CENTIPEDE_OBJS)
		$(CC) -o $(GAMES_DIR)/$(CENTIPEDE_NAME) $(CENTIPEDE_OBJS) -shared

clean:
		$(RM) $(SNAKE_OBJS)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(SNAKE_OBJS)
		$(RM) $(SOLARFOX_OBJS)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(SOLARFOX_OBJS)
		$(RM) $(CENTIPEDE_OBJS)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(CENTIPEDE_OBJS)

fclean:         clean
		$(RM) $(GAMES_DIR)/$(SNAKE_NAME)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(SNAKE_NAME)
		$(RM) $(GAMES_DIR)/$(SOLARFOX_NAME)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(SOLARFOX_NAME)
		$(RM) $(GAMES_DIR)/$(CENTIPEDE_NAME)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(CENTIPEDE_NAME)

re:             fclean all

.PHONY:         all clean fclean re
