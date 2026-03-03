# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/03 18:50:08 by apolleux          #+#    #+#              #
#    Updated: 2026/03/03 19:07:03 by apolleux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 				:= cc
CFLAGS			:= -Wall -Werror -Wextra

INCLUDES_DIR	:= -Iincludes/
NAME			:= minitalk

LIBFT_DIR		:= includes/libft/
LIBFT			:= $(LIBFT_DIR)libft.a

PRINTF_DIR		:= includes/ft_printf/
PRINTF			:= $(PRINTF_DIR)libftprintf.a

SRCS			:=	server.c\
					client.c

OBJS			:= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	@echo "\nBuild complete ;)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDES_DIR)  $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	@echo "Libft [COMPILING]"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(PRINTF):
	@echo "ft_printf [COMPILING]"
	@$(MAKE) -C $(PRINTF_DIR) --no-print-directory

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES_DIR) -c $< -o $@

clean:
	@echo "Clean"
	@rm -rf $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(PRINTF_DIR) clean --no-print-directory

fclean: clean
	@echo "Fclean"
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(PRINTF_DIR) clean --no-print-directory
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re