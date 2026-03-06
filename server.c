/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:24:36 by apolleux          #+#    #+#             */
/*   Updated: 2026/03/06 22:02:32 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "minitalk.h"

static void	join_doe(char character)
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

static void	handle_signal(int signal)
{
	static unsigned char	temp_char = 0;
	static int				bits = 8;

	temp_char <<= 1;
	if (signal == SIGUSR2)
		temp_char++;
	bits--;
	if (bits == 0)
	{
		join_doe(temp_char);
		temp_char = 0;
		bits = 8;
	}
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
