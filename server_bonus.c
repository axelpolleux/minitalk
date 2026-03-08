/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:24:36 by apolleux          #+#    #+#             */
/*   Updated: 2026/03/08 18:26:57 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "minitalk_bonus.h"

t_tab	g_tab;

static void	table_management(char character)
{
	char	*new_string;

	g_tab.size++;
	if (g_tab.size >= g_tab.capacity - 1)
	{
		g_tab.capacity *= 2;
		new_string = ft_calloc(g_tab.capacity, sizeof(char));
		if (!new_string)
			return ;
		ft_strlcpy(new_string, g_tab.string, g_tab.size);
		free(g_tab.string);
		g_tab.string = new_string;
		free(new_string);
	}
	g_tab.string[g_tab.size] = character;
}

static void	join_doe(char character, siginfo_t *info)
{
	static char	*res;

	if (character == '\0')
	{
		write(1, g_tab.string, g_tab.size);
		write(1, &"\n", 1);
		free(g_tab.string);
		g_tab.string = NULL;
		kill(info->si_pid, SIGUSR2);
	}
	else
		table_management(character);
}

static void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	temp_char = 0;
	static int				bits = 8;

	(void)context;
	temp_char <<= 1;
	if (signal == SIGUSR2)
		temp_char++;
	bits--;
	if (bits == 0)
	{
		join_doe(temp_char, info);
		temp_char = 0;
		bits = 8;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	ft_printf("Process ID: %d\n", pid);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
