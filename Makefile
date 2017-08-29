NAME = lem-in

FLAGS = -Wall -Wextra -Werror -g

SRC =	\
		srcs/lem-in.c \
		srcs/misc.c \
		srcs/save_rooms.c \
		srcs/save_links.c \
		srcs/find_path.c \
		srcs/send_ant.c \
		srcs/error_check.c

INPUT_OBJ =	\
		lem-in.o \
		misc.o \
		save_rooms.o \
		save_links.o \
		find_path.o \
		send_ant.o \
		error_check.o
		
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

fast: $(OBJ) lem-in.h
	make -C libft/
	gcc $(FLAGS) -I libft -c $(SRC)
	gcc -o $(NAME) $(OBJ) -lm -L libft/ -lft
	make -C libft/ clean
	/bin/rm -f $(OBJ)
	/bin/rm -f $(INPUT_OBJ)

re: fclean all
	
.PHONY: clean fclean
