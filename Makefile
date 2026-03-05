# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/03 18:50:08 by apolleux          #+#    #+#              #
#    Updated: 2026/03/05 14:49:40 by apolleux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 				:= cc
CFLAGS			:= -Wall -Werror -Wextra

INCLUDES_DIR	:= -Iincludes/

LIBFT_DIR		:= includes/libft/
LIBFT			:= $(LIBFT_DIR)libft.a

PRINTF_DIR		:= includes/ft_printf/
PRINTF			:= $(PRINTF_DIR)libftprintf.a

SRCS			:=	server.c\
					client.c

OBJS			:= $(SRCS:.c=.o)

all: server client

server: $(LIBFT) $(PRINTF) $(OBJS)
	@$(CC) $(CFLAGS) server.o $(INCLUDES_DIR)  $(LIBFT) $(PRINTF) -o server

client: $(LIBFT) $(PRINTF) $(OBJS)
	@$(CC) $(CFLAGS) client.o $(INCLUDES_DIR)  $(LIBFT) $(PRINTF) -o client


#$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
#	@server
#	@client
#	@echo "\nBuild complete ;)\n"

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