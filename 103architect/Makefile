##
## Makefile for Makefile in /home/Toinouxx/B1_Mathematics/103architect
## 
## Made by Antoine Yvroud
## Login   <Toinouxx@epitech.net>
## 
## Started on  Wed Dec 14 18:03:32 2016 Antoine Yvroud
## Last update Wed Dec 14 18:39:02 2016 Guillaume
##

ECHO	=	echo -e

CC	=	gcc

CFLAGS	+=	-Wall -Werror -Wextra -I include -lm

RM	=	rm -f

NAME	=	103architect

SRCS	=	103architect.c	\
		matrice.c

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

all:	$(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@$(ECHO) '\033[1;32m> Compiled\033[0m'

clean:
	$(RM) $(OBJS)
	@$(ECHO) '\033[1;35m> Directory cleaned\033[0m'

fclean:	clean
	$(RM) $(NAME)
	@$(ECHO) '\033[1;35m> Remove executable\033[0m'

re:	fclean all

.PHONY: all clean re
