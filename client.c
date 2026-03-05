/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:24:31 by apolleux          #+#    #+#             */
/*   Updated: 2026/03/05 14:51:48 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minitalk.h"

void	client(int signal, int pid, char *send)
{
	(void)signal;
	(void)pid;
	(void)send;
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_printf("Message %s --> to server %s", argv[2], argv[1]);
	}
	return (0);
}