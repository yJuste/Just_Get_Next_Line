NAME = get_next_line

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	$(CC) -I $(CFLAGS) -c $(CFLAGS) $(SRC)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

rf : re
	rm -f $(OBJ)
	rm -f $(NAME)

s:	
	ls -lh $(NAME)

.PHONY: all bonus clean fclean re rf s dev
