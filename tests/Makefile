NAME = test

SOURCE = main2.c

OBJ = $(SOURCE:.c=.o)

all:  $(NAME)

$(NAME):
		make -C ../ re
			gcc -Wall -Wextra -Werror -c $(SOURCE) -I ../ft_printf.h
				gcc -o $(NAME) $(OBJ) ../libftprintf.a

clean:
		rm -f $(OBJ)
			make -C ../ clean

fclean: clean
		rm -f $(NAME)
			make -C ../ fclean

re: fclean all

