NAME		=	ft_ping
SHEL		=	/bin/bash

CC			=	gcc
CFLAGS		=	-g -Wall -Wextra -Werror

LIBFT_DIR	=	./libft/
SRCS_DIR	=	srcs/
SRCS_LIST	=	ft_ping.c		\
				wrapper.c

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))
OBJS_DIR	=	objs/
OBJS_LIST	=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))
HEADERS		=	-I./libft/includes -I./includes
LIBS		=	./libft/libft.a

.PHONY : all clean fclean norme re

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LIBFT_DIR)
	@echo "\033[37mLinking...\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(HEADERS) $(OBJS) $(LIBS)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "\033[34mCompilation of \033[36m$(notdir $<)\033[34m done.\033[0m"

norme :
	@norminette $(SRCS)

clean :
	@rm -rf $(OBJS_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo "\033[31mObjects files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31m removed.\033[0m"

fclean :
	@rm -rf $(OBJS_DIR)
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re : fclean all