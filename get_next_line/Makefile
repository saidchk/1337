NAME = get_next_line
SRC = get_next_line.c  get_next_line_utils.c 
OBJ = $(SRC:*.c=*.o)
 
FLG = -Wall -Werror -Wextra
LFT = -L./libft -lft
SANIT = -fsanitize=address
INPUT = example.txt

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC)
	@gcc  $(FLG) -c $(SRC) 
	@ar rcs $(NAME) $(obj)  

clean:
	@rm -f *.o
	@rm -rf *.dSYM
	@rm -f .nfs.*
	@rm -f *DS_Store

fclean: clean
	@rm -f $(NAME)

re: fclean all

 