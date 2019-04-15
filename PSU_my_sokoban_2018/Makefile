##
## EPITECH PROJECT, 2018
## PSU_my_sokoban_2018
## File description:
## Makefile
##

NAME	=	my_sokoban

CC	=	gcc

RM	=	rm -f

SRCS	=	./src/main/main.c						\
			./src/error_management/error_manage_1.c	\
			./src/error_management/error_manage_2.c	\
			./src/parse_map/map_parsing.c			\
			./src/game/get_positions.c				\
			./src/game/draw_game.c					\
			./src/game/end_game.c					\
			./src/game/event_management.c			\
			./src/game/movement_management.c		\
			./src/game/collisions.c					\
			./src/game/restart_game.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS =	-g -Iinclude -Llib -lmy -lncurses -Wall -Wextra

all:	$(NAME)

$(NAME): $(OBJS)
	cd lib/my && make
	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) lib/libmy.a
	$(RM) lib/my/libmy.a

re: fclean all clean

debug: $(OBJS)
	$(CC) -g $(OBJS) -o $(NAME) $(CFLAGS)

.PHONY: all clean fclean re
