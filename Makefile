NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

GNLSRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
GNLOBJ = $(GNLSRC:.c=.o)

PRINTFSRC = ./ft_printf/arg_functions/print_hex.c ./ft_printf/arg_functions/print_ptr_hex.c ./ft_printf/arg_functions/print_int.c ./ft_printf/arg_functions/print_uint.c ./ft_printf/arg_functions/print_str.c \
			./ft_printf/ft_printf.c
PRINTFOBJ = $(PRINTFSRC:.c=.o)

LIBFTSRC = ./ft_printf/libft/ft_isalpha.c ./ft_printf/libft/ft_putnbr_fd.c ./ft_printf/libft/ft_putendl_fd.c ./ft_printf/libft/ft_putstr_fd.c \
./ft_printf/libft/ft_striteri.c ./ft_printf/libft/ft_putchar_fd.c ./ft_printf/libft/ft_split.c ./ft_printf/libft/ft_strmapi.c ./ft_printf/libft/ft_strtrim.c \
./ft_printf/libft/ft_itoa.c ./ft_printf/libft/ft_strjoin.c ./ft_printf/libft/ft_substr.c ./ft_printf/libft/ft_strdup.c ./ft_printf/libft/ft_calloc.c ./ft_printf/libft/ft_atoi.c \
./ft_printf/libft/ft_strnstr.c ./ft_printf/libft/ft_isdigit.c ./ft_printf/libft/ft_memchr.c ./ft_printf/libft/ft_memcmp.c ./ft_printf/libft/ft_strncmp.c ./ft_printf/libft/ft_strrchr.c \
./ft_printf/libft/ft_isalnum.c ./ft_printf/libft/ft_strchr.c ./ft_printf/libft/ft_isascii.c ./ft_printf/libft/ft_isprint.c ./ft_printf/libft/ft_strlen.c ./ft_printf/libft/ft_tolower.c \
./ft_printf/libft/ft_memset.c ./ft_printf/libft/ft_bzero.c ./ft_printf/libft/ft_memcpy.c ./ft_printf/libft/ft_memmove.c ./ft_printf/libft/ft_strlcpy.c ./ft_printf/libft/ft_strlcat.c ./ft_printf/libft/ft_toupper.c
LIBFTOBJ = $(LIBFTSRC:.c=.o)

SRC = main.c map_read.c map_check.c map_render.c player_movement.c game_close.c map_update.c
OBJ = $(SRC:.c=.o)

MLX = ./MLX/
MLX_LINUX = ./MLX_LINUX/

all: $(NAME)

$(NAME): $(OBJ) $(PRINTFSRC) $(LIBFTSRC) $(GNLOBJ)
	make -C ft_printf/
	make -C $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTFOBJ) $(LIBFTOBJ) $(GNLOBJ) $(MLX)*.a -framework OpenGl -framework AppKit -o $(NAME)

clean:
	make clean -C ./ft_printf
	make clean -C $(MLX)
	$(RM) $(OBJ) $(GNLOBJ)

fclean: clean
	make fclean -C ./ft_printf
	$(RM) $(NAME)

norm:
	@norminette ft_printf
	@norminette get_next_line
	@norminette ./*.h
	@norminette ./*.c

re: fclean all