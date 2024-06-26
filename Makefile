NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = ft_split.c util.c push_swap.c free_function.c \
		list_function.c check_paring.c opiration_stack.c \
		best_mix.c best_rr.c best_rrr.c opiration_stack_suit.c \
		sort_fuction.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

%.o: %.c push_swap.h
		$(CC) $(CFLAGS) -o $@ -c $<

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean