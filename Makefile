CC		 = cc
NAME	 = libftprintf.a
CFLAGS	 = -Wall -Wextra -Werror
RM		 = rm -rf
AR		 = ar rc
FILES	 = ft_printf.c ft_parse.c ft_print_c.c ft_print_d.c ft_print_per.c ft_print_s.c ft_print_p.c ft_print_u.c ft_print_x.c ft_printf_utils.c
SRCDIR  := srcs
OBJDIR  := objs
INCDIR  := includes
SRCS	:= $(addprefix $(SRCDIR)/, $(FILES))
OBJS	:= $(addprefix $(OBJDIR)/, $(FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

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
