NAME = lem-in

FLAGS = -Wall -Wextra -Werror -g

SRC =	\
		lem-in.c

INPUT_OBJ =	\
		lem-in.o
		
OBJ = $(patsubst %.c,%.o,$(addprefix ./, $(SRC)))

all: $(NAME)

$(NAME): $(OBJ) lem-in.h
	make -C libft/
	gcc $(FLAGS) -I libft -c $(SRC)
	gcc -o $(NAME) $(OBJ) -lm -L libft/ -lft

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)
	/bin/rm -f $(INPUT_OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
	
.PHONY: clean fclean
