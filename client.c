/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:24:31 by apolleux          #+#    #+#             */
/*   Updated: 2026/03/05 18:17:53 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <signal.h>

void	send_signal(int pid, unsigned char bit)
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
	}
	usleep(42);
	return ;
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (!pid)
			return (0);
		str = argv[2];
		while (*str)
			send_signal(pid, *str++);
	}
	else
		ft_printf("Invalid execution");
	return (0);
}
