# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 11:22:08 by lsoto-do          #+#    #+#              #
#    Updated: 2022/11/08 12:01:26 by lsoto-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
INCLUDES	=	include/
LIBFT		=	libft/
SRCS_DIR	=	src/
BONUS_DIR	= 	bonus/
OBJS_DIR	=	obj/
CFLAGS		=	-Wall -Werror -Wextra -I
RM			=	rm -f
AR			=	ar -rcs
BONUS_NAME	=	.bonus

#Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
ELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

###

FILES		=	ft_i_format ft_p_format ft_printf_utils ft_put_words ft_s_format ft_safe_free ft_uitoa ft_printf\
				ft_x_format ft_u_format

FILESBONUS 	=	ft_c_format_bonus ft_flags2_bonus ft_flags_bonus ft_i_format_bonus\
				ft_p_format_bonus ft_printf_bonus ft_printf_itoa_bonus\
				ft_printf_utils_bonus ft_put_words_bonus ft_safe_free_bonus ft_s_format_bonus\
				ft_u_format_bonus ft_uitoa_bonus ft_x_format_bonus

LIB_FILES	=	ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii\
				ft_isdigit ft_isprint ft_itoa ft_memchr ft_memcmp ft_memcpy\
	   			ft_memmove ft_strchr ft_strdup ft_strlcat ft_strlcpy ft_strlen\
	   			ft_strncmp ft_strnstr ft_strrchr ft_tolower ft_toupper ft_memset\
	   			ft_substr ft_strjoin ft_strtrim ft_strmapi ft_striteri\
	   			ft_putchar_fd ft_putendl_fd ft_putstr_fd ft_putnbr_fd ft_split\
				ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back\
				ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

SRCS 		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS		=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
SRC_BONUS	=	$(addprefix $(BONUS_DIR), $(addsuffix .c, $(FILESBONUS)))
OBJS_BONUS	= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILESBONUS)))
SRCS_LIB	= 	$(addprefix $(LIBFT)$(OBJS_DIR), $(addsuffix .o, $(LIB_FILES))) 
###

OBJSF		= .cache_exists

all:		$(NAME)

$(NAME):	$(OBJS) | make_libft
			@$(RM) $(NAME)
			@$(MAKE) make_libft
			@$(AR) $(NAME) $(OBJS)
			@ranlib $(NAME)
			@echo "$(GREEN)Printf compiled! $(DEF_COLOR)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJSF)
			@echo "$(CYAN)Compiling $< $(DEF_COLOR)"
			@$(CC) -MMD $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)%.o : $(BONUS_DIR)%.c | $(OBJSF)
			@echo "$(CYAN)Compiling $< $(DEF_COLOR)"
			@$(CC) -MMD $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSF):
			@mkdir -p $(OBJS_DIR)

bonus:	$(BONUS_NAME)	
	
$(BONUS_NAME) : ${OBJS_BONUS} | make_libft
			@$(RM) $(NAME)
			@$(MAKE) make_libft
			@$(AR) $(NAME) ${OBJS_BONUS}
			@ranlib $(NAME)
			@echo "$(GREEN)Printf bonus compiled$(DEF_COLOR)"
			@touch $@
make_libft:
	@make all -C $(LIBFT)
	@$(AR) $(NAME) $(SRCS_LIB)
clean:
		@$(RM) -rf $(OBJS_DIR)
		@$(RM) -r $(OBJSF)
		@echo "$(GREEN)Printf objects files cleaned!$(DEF_COLOR)"

fclean:	clean
		@$(RM) $(NAME)
		@make fclean -C $(LIBFT)
		@$(RM) $(BONUS_NAME)
		@echo "$(GREEN)Printf executable files cleaned!$(DEF_COLOR)"

re:		fclean all
		@echo "$(GREEN)Cleaned and rebuilt everything!$(DEF_COLOR)"

norm:
		@norminette

.PHONY:		all clean fclean re norm bonus make_libft
