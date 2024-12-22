HEADER = libft/libft.h

SRC =	pipex.c \

LIB_A = libft/libft.a

NAME =  pipex

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -f 

OBJ = $(SRC:%.c=%.o) 

CC = cc

all : $(NAME) 

$(NAME) :	$(OBJ)
			make -C libft
			$(CC) $(CFLAGS) $(OBJ) $(LIB_A) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJ)

fclean :	clean		
			$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean all re
