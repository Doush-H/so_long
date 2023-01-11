NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ./arg_functions/print_hex.c ./arg_functions/print_ptr_hex.c ./arg_functions/print_int.c ./arg_functions/print_uint.c ./arg_functions/print_str.c \
			ft_printf.c

OBJ = $(SRC:.c=.o)

LIBFTSRC = ./libft/*.c
LIBFTOBJ = $(LIBFTSRC:.c=.o)

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTOBJ)
	ar rcs $(NAME) $(OBJ) $(LIBFT)

$(LIBFTOBJ): $(LIBFTSRC)
	make -C ./libft/

clean:
	make clean -C ./libft/
	rm -f *.o ./arg_functions/*.o

fclean: clean
	make fclean -C ./libft/
	rm -f *.a

re: fclean all
	make re -C ./libft/