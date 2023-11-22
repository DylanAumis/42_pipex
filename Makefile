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

SRCS			= ${SRC_MAIN}

SRCS_BONUS		= ${BONUS}

LIBFT_DIR		= Libft/

OBJ_DIR			= objs
BONUS_OBJ_DIR		= bonus_objs
OBJS			= $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRCS))
BONUS_OBJS		= $(patsubst bonus/%.c,$(BONUS_OBJ_DIR)/%.o,$(SRCS_BONUS))

CC			= cc
RM			= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME            = pipex
NAME_BONUS      = pipex_bonus

all: $(OBJ_DIR) $(OBJS) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
$(BONUS_OBJ_DIR):
	@mkdir -p $(BONUS_OBJ_DIR)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@printf '\033[A\033[19C'"⌛ [\e[1;96mCompiling\033[0m]\033[35m $<\033[0m \n"
	@$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: bonus/%.c | $(BONUS_OBJ_DIR)
	@mkdir -p $(@D)
	@printf '\033[A\033[19C'"⌛ [\e[1;96mCompiling BONUS\033[0m]\033[35m $<\033[0m \n"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): 		$(OBJS)
			@make -s -C ${LIBFT_DIR}
			@$(CC) $(OBJS) $(CFLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)
			@printf '\033[A\033[20C'"\033[32;1m  ✅ Project has compiled successfully!          \033[0m"
			@printf "\n\n    [🏳️ FLAGS: \033[0;35m$(CFLAGS)\033[0m]"
			@echo "\033[32;1m\n 💾 Executable \e[7m./$(NAME)\e[27m has been created in: \n    └─ 📂 \033[4;36m ~ $(PWD)\033[0m"

$(NAME_BONUS): 		$(BONUS_OBJS)
			@make -s -C ${LIBFT_DIR}
			@$(CC) $(BONUS_OBJS) $(CFLAGS) -L$(LIBFT_DIR) -lft -o $(NAME_BONUS)
			@printf '\033[A\033[20C'"\033[32;1m  ✅ Project has compiled successfully!          \033[0m"
			@printf "\n\n    [🏳️ FLAGS: \033[0;35m$(CFLAGS)\033[0m]"
			@echo "\033[32;1m\n 💾 Executable \e[7m./$(NAME_BONUS)\e[27m has been created in: \n    └─ 📂 \033[4;36m ~ $(PWD)\033[0m"

bonus:			$(NAME_BONUS)
				

clean:
	$(RM) -r $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean:
	@echo "\033[1;93m\n                        [Cleaning directories with \033[0;96mfclean\033[1;93m]\n\033[0m"
	@make clean
	@make -C ${LIBFT_DIR} fclean
	$(RM) $(NAME) $(NAME_BONUS)

re:	
	@make fclean
	@echo "\033[1;93m\n                            [Calling \033[0;96mmake all\033[1;93m rule]\n\033[0m"
	@make -s all

.PHONY:	all clean fclean re
