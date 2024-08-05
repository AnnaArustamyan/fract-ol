NAME = fractol

SRCSPATH = ./src/
LIBFTPATH = ./libft/
PRINTFPATH = ./ft_printf/
INCPATH = ./includes/ ./libft/includes/ ./ft_printf/includes/

SRCS = $(wildcard $(SRCSPATH)*.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))
PRINTF = $(PRINTFPATH)libftprintf.a
LIBFT = $(LIBFTPATH)libft.a

CC = cc
DEBUG = -fsanitize=address
MLXFLAGS = -Lmlx -lmlx -framework OpenGl -framework Appkit -lm
CFLAGS = -Wall -Wextra -Werror $(foreach H,$(INCPATH),-I$(H)) #$(DEBUG)

all : $(NAME)

$(NAME) : $(PRINTF) $(LIBFT) $(OBJS)
	$(CC) $(MLXFLAGS) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $@

$(PRINTF) :
	make -C $(PRINTFPATH) all

$(LIBFT) :
	make -C $(LIBFTPATH) all

$(SRCSPATH)%.o : $(SRCSPATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make -C $(PRINTFPATH) clean
	make -C $(LIBFTPATH) clean
	rm -f $(OBJS)

fclean : clean
	make -C $(PRINTFPATH) fclean
	make -C $(LIBFTPATH) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re