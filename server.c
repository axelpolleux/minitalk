/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:24:36 by apolleux          #+#    #+#             */
/*   Updated: 2026/03/05 18:26:51 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minitalk.h"
#include <signal.h>

void	handle_signal(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("0");
	else
		ft_printf("1");
}

int	main(void)
{
	int	pid;
	
	pid = getpid();
	ft_printf("Process ID: %d\n", pid);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
