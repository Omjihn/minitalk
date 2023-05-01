/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:04:08 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/01 19:42:22 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_vars_c	g_vars;

void	ft_send_len(int pid)
{
	if (g_vars.len & g_vars.i)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	g_vars.i *= 2;
	if (g_vars.i > 2147483648)
	{
		g_vars.len_is_send = 1;
		G_vars.i = 1;
	}
}

void	ft_send_str(int pid)
{
	if (G_vars.i > 128)
	{
		g_vars.i = 1;
		g_vars.oct++;
	}
	if (g_vars.i <= 128 && g_vars.oct < g_vars.len)
	{
		if (g_vars.str[g_vars.oct] & g_vars.i)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		g_vars.i *= 2;
	}
}

void	ft_send(int sig)
{
	if (sig == SIGUSR2)
		exit(ft_printf("Message recieved by the server\n"));
	if (g_vars.len_is_send == 0)
		ft_send_len(g_vars.pid);
	else
		ft_send_str(g_vars.pid);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		exit (ft_printf("Please enter a PID and your message\n"));
	g_vars.pid = ft_atoi(argv[1]);
	g_vars.len = ft_strlen(argv[2]);
	if (vars.len == 0)
		exit (ft_printf("Nothing to send\n"));
	g_vars.i = 1;
	g_vars.oct = 0;
	g_vars.str = argv[2];
	g_vars.len_is_send = 0;
	if (kill(g_vars.pid, SIGUSR1) == -1)
		exit(ft_printf("Error server not found\n"));
	signal(SIGUSR1, ft_send);
	signal(SIGUSR2, ft_send);
	while (1)
		pause();
	return (0);
}
