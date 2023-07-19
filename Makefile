# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daumis <daumis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 00:23:25 by daumis            #+#    #+#              #
#    Updated: 2023/07/19 15:08:01 by daumis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_MAIN		=	src/main.c \
				src/parsing.c \
				src/pipex.c \
				src/free.c

BONUS			=	bonus/main_bonus.c \
				bonus/parsing_bonus.c \
				bonus/pipex_bonus.c \
				bonus/heredoc_bonus.c \
				bonus/free_bonus.c

SRCS			=	${SRC_MAIN}

SRCS_BONUS		=	${BONUS}

LIBFT_DIR		=	Libft/

OBJ			=	$(SRCS:.c=.o)
BONUS_OBJ		=	$(BONUS:.c=.o)

CC			=	cc
RM			=	rm -f
CFLAGS			=	-Wall -Wextra -Werror

NAME			=	pipex
NAME_BONUS		=	pipex_bonus

all:			$(NAME)

$(NAME): 		$(OBJ)
				@echo "\033[1;35m\n                              ⌛️Compiling files...\033[0m"
				@make -s -C ${LIBFT_DIR}
				$(CC) $(OBJ) $(CFLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)
				@echo "\033[32;1m\n                     Project has compiled successfully! ✅ \033[0m"
				@echo "\033[32;1m\n 💾 Executable './$(NAME)' has been created in: \n    └─ 📂 \033[4;36m ~ $(PWD)\033[0m"

$(NAME_BONUS): 	$(BONUS_OBJ)
				@echo "\033[1;35m\n                          ⌛️Compiling BONUS files...\n\033[0m"
				@make -s -C ${LIBFT_DIR}
				$(CC) $(BONUS_OBJ) $(CFLAGS) -L$(LIBFT_DIR) -lft -o $(NAME_BONUS)
				@echo "\033[32;1m\n                     Project has compiled successfully! ✅ \033[0m"
				@echo "\033[32;1m\n 💾 Executable './$(NAME_BONUS)' has been created in: \n    └─ 📂 \033[4;36m ~ $(PWD)\033[0m"

bonus:			$(NAME_BONUS)
				

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean:
	@echo "\033[1;33m\n                        [Cleaning directories with \033[0;36mfclean\033[1;33m]\n\033[0m"
	@make clean
	@make -C ${LIBFT_DIR} fclean
	$(RM) $(NAME) $(NAME_BONUS)

re:	
	@make fclean
	@echo "\033[1;33m\n                            [Calling \033[0;36mmake all\033[1;33m rule]\n\033[0m"
	@make -s all

.PHONY:	all clean fclean re
