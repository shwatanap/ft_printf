SRCS	 = ft_printf.c ft_parse.c ft_print_c.c ft_print_d.c ft_print_s.c ft_print_p.c ft_print_u.c ft_print_x.c ft_printf_utils.c
OBJS	 = $(SRCS:.c=.o)
CC		 = cc
NAME	 = libftprintf.a
CFLAGS	 = -Wall -Wextra -Werror
RM		 = rm -rf
AR		 = ar rc

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
	norminette $(SRCS)

debug: $(NAME)
	$(CC) main.c $(NAME)
	./a.out

.PHONY: all clean fclean re bonus
