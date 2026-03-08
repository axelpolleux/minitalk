/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:24:36 by apolleux          #+#    #+#             */
/*   Updated: 2026/03/08 20:50:22 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "minitalk.h"

t_tab	g_tab;

static void	table_management(char character)
{
	char	*new_string;

	if (g_tab.size >= g_tab.capacity - 1)
	{
		g_tab.capacity *= 2;
		new_string = ft_calloc(g_tab.capacity, sizeof(char));
		if (!new_string)
			return ;
		ft_strlcpy(new_string, g_tab.string, g_tab.size + 1);
		free(g_tab.string);
		g_tab.string = new_string;
	}
	g_tab.string[g_tab.size] = character;
	g_tab.size++;
}

static void	join_doe(char character)
{
	if (character == '\0')
	{
		write(1, g_tab.string, g_tab.size);
		write(1, "\n", 1);
		free(g_tab.string);
		g_tab.capacity = 10;
		g_tab.size = 0;
		g_tab.string = ft_calloc(g_tab.capacity, sizeof(char));
	}
	else
		table_management(character);
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
	g_tab.size = 0;
	g_tab.capacity = 10;
	g_tab.string = ft_calloc(g_tab.capacity, sizeof(char));
	if (!g_tab.string)
		return (0);
	ft_printf("Process ID: %d\n", pid);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
