# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 12:40:36 by lsoto-do          #+#    #+#              #
#    Updated: 2022/10/17 12:42:09 by lsoto-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
INCLUDES	=	../include
SRCS_DIR	=	src/
OBJS_DIR	=	obj/
CFLAGS		=	-Wall -Werror -Wextra -I
RM			=	rm -f
AR			=	ar rcs


#Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

###

FILES		=	ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii\
				ft_isdigit ft_isprint ft_itoa ft_memchr ft_memcmp ft_memcpy\
	   			ft_memmove ft_strchr ft_strdup ft_strlcat ft_strlcpy ft_strlen\
	   			ft_strncmp ft_strnstr ft_strrchr ft_tolower ft_toupper ft_memset\
	   			ft_substr ft_strjoin ft_strtrim ft_strmapi ft_striteri\
	   			ft_putchar_fd ft_putendl_fd ft_putstr_fd ft_putnbr_fd ft_split\
				ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back\
				ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

SRC_FILES		+= $(addprefix $(SRC_DIR), $(FILES))

SRCS 		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS		=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJSF		= .cache_exists

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@ranlib $(NAME)
			@echo "$(GREEN)Libft compiled! $(DEF_COLOR)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJSF)
			@echo "$(CYAN)Compiling $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSF):
			@mkdir -p $(OBJS_DIR)

clean:
		@$(RM) -rf $(OBJS_DIR)
		@$(RM) -r $(OBJSF)
		@echo "$(GREEN)Libft objects files cleaned!$(DEF_COLOR)"

fclean:	clean
		@$(RM) -f $(NAME)
		@echo "$(GREEN)Libft executable files cleaned!$(DEF_COLOR)"

re:		fclean all
		@echo "$(GREEN)Cleaned and rebuilt everything!$(DEF_COLOR)"

norm:
		@norminette $(SRCS) $(INCLUDES)

.PHONY:		all clean fclean re norm
