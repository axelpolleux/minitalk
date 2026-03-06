# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/03 18:50:08 by apolleux          #+#    #+#              #
#    Updated: 2026/03/06 23:02:05 by apolleux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 				:= cc
CFLAGS			:= -Wall -Werror -Wextra -g

INCLUDES_DIR	:= -Iincludes/

LIBFT_DIR		:= includes/libft/
LIBFT			:= $(LIBFT_DIR)libft.a

PRINTF_DIR		:= includes/ft_printf/
PRINTF			:= $(PRINTF_DIR)libftprintf.a

SRCS			:=	server.c\
					client.c


SRCS_BONUS		:=	server_bonus.c \
					client_bonus.c

OBJS			:= $(SRCS:.c=.o)
OBJS_BONUS		:= $(SRCS_BONUS:.c=.o)

all: server client

server: $(LIBFT) $(PRINTF) $(OBJS)
	@$(CC) $(CFLAGS) server.o $(INCLUDES_DIR)  $(LIBFT) $(PRINTF) -o server

client: $(LIBFT) $(PRINTF) $(OBJS)
	@$(CC) $(CFLAGS) client.o $(INCLUDES_DIR)  $(LIBFT) $(PRINTF) -o client

bonus:	client_bonus server_bonus

server_bonus: $(LIBFT) $(PRINTF) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) server_bonus.o $(INCLUDES_DIR)  $(LIBFT) $(PRINTF) -o server_bonus

client_bonus: $(LIBFT) $(PRINTF) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) client_bonus.o $(INCLUDES_DIR)  $(LIBFT) $(PRINTF) -o client_bonus

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
	@rm -rf $(OBJS_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(PRINTF_DIR) clean --no-print-directory

fclean: clean
	@echo "Fclean"
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(PRINTF_DIR) clean --no-print-directory
	@rm -rf server client 
	@rm -rf server_bonus client_bonus

re: fclean all

.PHONY: all clean fclean re