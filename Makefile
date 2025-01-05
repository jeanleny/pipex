HEADER = libft/libft.h

OBJDIR = obj_files

CDIR = src/

SRC =	$(CDIR)pipex.c 		\
		$(CDIR)pipex_utils.c	\
		$(CDIR)pipex_check.c	\

LIB_A = libft/libft.a

NAME =  pipex

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -rf 

OBJ = $(addprefix $(OBJDIR)/,$(SRC:$(CDIR)%.c=%.o)) 

CC = cc

all : $(NAME) 

$(NAME) :	$(OBJ)
			@make -C libft --no-print-directory
			@$(CC) $(CFLAGS) $(OBJ) $(LIB_A) -o $(NAME)
			@echo  "\e[1;4mPipex Compiled ✅"

$(OBJDIR)/%.o: $(CDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean : 
	@$(RM) $(OBJ) $(OBJDIR)
	@make clean -C libft --no-print-directory

fclean :	clean		
			@$(RM) $(NAME)
			@make fclean -C libft --no-print-directory

re : fclean all

.PHONY : clean fclean all re
