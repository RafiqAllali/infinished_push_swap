SOURCE =   push_swap.c split.c push_swap_utils.c

RM = rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SOURCE:.c=.o)

AR = ar rc

NAME = push_swap

%.o: %.c push_swap.h
	$(CC)  $(CFLAGS) -c $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
all: $(NAME)
 
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all