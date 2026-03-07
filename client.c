/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:24:31 by apolleux          #+#    #+#             */
/*   Updated: 2026/03/07 16:41:47 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "minitalk.h"

static void	send_signal(int pid, unsigned char bit)
{
	int				i;
	unsigned char	c;

	i = 8;
	c = bit;
	while (i > 0)
	{
		i--;
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(300);
	}
	return ;
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

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
