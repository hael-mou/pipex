# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 07:53:28 by hael-mou          #+#    #+#              #
#    Updated: 2023/01/16 12:26:22 by hael-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

# Dir :
INCLUDE		= include
SRC_DIR		= src/
OBJ_DIR		= obj/
LIBFT_DIR	= libft/
OBJF		= .cache

# command :
CC 		= cc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

# Colors :
DEF_COLOR	= \033[0;39m
GRAY		= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;40m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m

# files:
SRC_FILES	= pipex pipex_commadpath pipex_split_command pipex_files pipex_execute pipex_error\
				heredoc pipex_clean
SRC			= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

LIBFT		= libft.a

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDE)/pipex.h | $(OBJF)
	@$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $@
	@echo "$(MAGENTA)# Pipex Compiling :$(GREEN) $< $(DEF_COLOR)"

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@$(CC) $(FLAGS) -I $(INCLUDE) $(LIBFT_DIR)$(LIBFT)  $^ -o $@
	@echo "$(YELLOW)# Program is created : Pipex$(DEF_COLOR)"

$(OBJF):
	@mkdir -p $(OBJ_DIR)

bonus: re

clean:
	@make clean -C libft/
	@$(RM) $(OBJ_DIR)
	@echo "$(RED) # Remove : \"Pipex  Object files cleaned!\" $(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_DIR)$(LIBFT)
	@echo "$(GRAY) # Remove : \"libft.a file cleaned!\" $(DEF_COLOR)"
	@echo "$(GRAY) # Remove : \"$(NAME) executable file cleaned!\" $(DEF_COLOR)"

re: fclean all

.PHONY:	all clean fclean re
