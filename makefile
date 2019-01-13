NAME = ft_ls

FILE = *.c

INCLD = ./src/libft/libft.a

FLAGE = -Wall -Wextra -Werror


all: $(NAME)

$(NAME):	
	gcc $(FLAGE) -o $(NAME) $(FILE) $(INCLD)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
