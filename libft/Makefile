NAME = libft.a

CC = gcc

SRCS =	\
		ft_free_2d.c \
		error_check.c \
		ft_paragraph.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_strcmp.c \
		ft_strlen.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_strcpy.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memalloc.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strdup.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_putendl.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_isspace.c \
		ft_last_word.c \
		ft_isneg.c \
		ft_search_and_replace.c \
		ft_isupper.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		get_next_line.c \
		ft_printf.c \
		flags.c \
		characters.c \
		strings.c \
		num.c \
		unumbers.c \
		xnumbers.c \
		onumbers.c \
		pointers.c \

OBJS =	\
		ft_free_2d.o \
		error_check.o \
		ft_paragraph.o \
		ft_putchar.o \
		ft_putstr.o \
		ft_putnbr.o \
		ft_strcmp.o \
		ft_strlen.o \
		ft_atoi.o \
		ft_isalpha.o \
		ft_strcpy.o \
		ft_memset.o \
		ft_bzero.o \
		ft_memcpy.o \
		ft_memccpy.o \
		ft_memalloc.o \
		ft_memmove.o \
		ft_memchr.o \
		ft_memcmp.o \
		ft_strdup.o \
		ft_strncpy.o \
		ft_strcat.o \
		ft_strncat.o \
		ft_strlcat.o \
		ft_strchr.o \
		ft_strrchr.o \
		ft_strstr.o \
		ft_strnstr.o \
		ft_strncmp.o \
		ft_isdigit.o \
		ft_isalnum.o \
		ft_isascii.o \
		ft_isprint.o \
		ft_toupper.o \
		ft_tolower.o \
		ft_memdel.o \
		ft_strnew.o \
		ft_strdel.o \
		ft_strclr.o \
		ft_striter.o \
		ft_striteri.o \
		ft_strmap.o \
		ft_strmapi.o \
		ft_strequ.o \
		ft_strnequ.o \
		ft_strsub.o \
		ft_strjoin.o \
		ft_putendl.o \
		ft_putchar_fd.o \
		ft_putstr_fd.o \
		ft_putendl_fd.o \
		ft_putnbr_fd.o \
		ft_strtrim.o \
		ft_strsplit.o \
		ft_itoa.o \
		ft_isspace.o \
		ft_last_word.o \
		ft_isneg.o \
		ft_search_and_replace.o \
		ft_isupper.o \
		ft_lstnew.o \
		ft_lstdelone.o \
		ft_lstdel.o \
		ft_lstadd.o \
		ft_lstiter.o \
		ft_lstmap.o \
		get_next_line.o \
		ft_printf.o \
		flags.o \
		characters.o \
		strings.o \
		num.o \
		unumbers.o \
		xnumbers.o \
		onumbers.o \
		pointers.o \

CFLAGS = -c -Wall -Werror -Wextra

LIB = ar rc

RLIB = ranlib

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) 
	$(LIB) $(NAME) $(OBJS)
	$(RLIB) $(NAME)

clean: 
	/bin/rm -rf $(OBJS)

fast: clean
	gcc main.c $(NAME)

fclean: clean
	/bin/rm -rf $(NAME) 

re: fclean all

.PHONY: clean
