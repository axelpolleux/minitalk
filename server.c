/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:24:36 by apolleux          #+#    #+#             */
/*   Updated: 2026/03/05 18:12:56 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minitalk.h"

void	usr1()
{
	ft_printf("0");
}

void	usr2()
{
	ft_printf("1");
}

int	main(void)
{
	int	pid;
	
	pid = getpid();
	ft_printf("Process ID: %d\n", pid);
	signal(SIGUSR1, usr1);
	signal(SIGUSR2, usr2);
	while (1)
		pause();
	return (0);
}
