/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:24:36 by apolleux          #+#    #+#             */
/*   Updated: 2026/03/07 20:10:37 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "minitalk_bonus.h"

static void	join_doe(char character, siginfo_t *info)
{
	static char	*res;
	char		*tmp;
	char		in_the_end[2];

	if (character == '\0')
	{
		write(1, res, ft_strlen(res));
		write(1, &"\n", 1);
		free(res);
		res = NULL;
		kill(info->si_pid, SIGUSR2);

	}
	else
	{
		in_the_end[0] = character;
		in_the_end[1] = '\0';
		if (!res)
			res = ft_strdup(in_the_end);
		else
		{
			tmp = res;
			res = ft_strjoin(tmp, in_the_end);
			free(tmp);
		}
	}
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
