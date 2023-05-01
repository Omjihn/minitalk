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

#include "minitalk_bonus.h"

t_vars_c	vars;

void	ft_send_len(int pid)
{
	if (vars.len & vars.i)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	vars.i *= 2;
}

void	ft_send_str(int pid)
{
	if (vars.i <= 128)
	{
		if (vars.str[vars.oct] & vars.i)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		vars.i *= 2;
	}
	else
	{
		vars.i = 1;
		vars.oct++;
		if (vars.str[vars.oct] & vars.i)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		vars.i *= 2;
	}
	if (vars.i > 2147483648)
		vars.len_is_send = 1;
}

void	ft_send(int sig)
{
//	if (sig == 10);
//		exit(ft_printf("Message recieved by the server\n"));
	usleep(100);
	if (vars.len_is_send == 0)
		ft_send_len(vars.pid);
	else
		ft_send_str(vars.pid);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		exit (ft_printf("Please enter a PID and your message\n"));
	vars.pid = ft_atoi(argv[1]);
	vars.len = ft_strlen(argv[2]);
	if (vars.len == 0)
		exit (ft_printf("Nothing to send\n"));
	vars.i = 1;
	vars.oct = 0;
	vars.str = argv[2];
	vars.len_is_send = 0;
	kill(vars.pid, SIGUSR1);
	signal(SIGUSR1, ft_send);
	signal(SIGUSR2, ft_send);
	while (1)
	{
		sleep(5);
		exit(ft_printf("Time out, try to check your pid\n"));
	}
	return (0);
}
