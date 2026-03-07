/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:24:31 by apolleux          #+#    #+#             */
/*   Updated: 2026/03/07 20:24:00 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "minitalk_bonus.h"

volatile sig_atomic_t	g_server_ready = 0;

static void	sig_server(int signal)
{
	if (signal == SIGUSR1)
		g_server_ready = 1;
	else if (signal == SIGUSR2)
		ft_printf("Message sent to server\n");
}

static void	send_signal(int pid, unsigned char bit)
{
	int				i;
	unsigned char	c;

	i = 8;
	c = bit;
	while (i > 0)
	{
		i--;
		g_server_ready = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_server_ready)
			pause();
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	signal(SIGUSR1, sig_server);
	signal(SIGUSR2, sig_server);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
		{
			ft_printf("invalid PID\n");
			return (1);
		}
		str = argv[2];
		while (*str)
			send_signal(pid, *str++);
		send_signal(pid, '\0');
	}
	else
	{
		ft_printf("Invalid execution: ./client <pid> <message>\n");
		exit(1);
	}
	return (0);
}
