NAME		= libft.a

# Dir:
INCLUDE		= ../include
SRC_DIR		= src/
OBJ_DIR		= obj/
OBJF		= .cache

# files:
SRC_FILES	 =	ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii \
				ft_isdigit ft_isprint ft_itoa ft_memchr ft_memcmp ft_memcpy \
				ft_memmove ft_memset ft_putchar_fd ft_putendl_fd ft_putnbr_fd \
				ft_putstr_fd ft_split ft_strchr ft_strdup ft_strjoin ft_strlcat \
				ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr ft_strrchr \
				ft_strtrim ft_striteri ft_substr ft_tolower ft_toupper
SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

# Command:
CC		:= cc
AR		:= ar rc
RM		:= rm -rf
FLAGS 	:= -Wall -Wextra -Werror

# color:
DEF_COLOR	= \033[0;39m
GRAY		= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@$(CC) -c $(FLAGS) -I $(INCLUDE) $< -o $@
	@echo "$(BLUE)# Libft Compiling :$(GREEN) $< $(DEF_COLOR)"

all: $(NAME)

$(OBJF):
			@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@$(AR) $@ $^
	@echo "$(WHITE)# lib is created : libft$(DEF_COLOR)"

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(RED) # Remove : \"LIBFT Object files cleaned!\" $(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GRAY) # Remove : \"$(NAME) file cleaned!\" $(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re
