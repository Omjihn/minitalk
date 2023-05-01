/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:04:00 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/01 19:40:06 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_free_all(t_vars_s *vars)
{
	ft_printf("%s\n", vars->str);
	free (vars->str);
	free (vars);
}

void	ft_bin_len(t_vars_s *vars, int sig)
{
	if (vars->i <= 2147483648)
	{
		if (sig == 10)
			vars->max_len += vars->i;
		vars->i *= 2;
	}
	if (vars->i > 2147483648)
	{
		vars->str = (char *) ft_calloc (sizeof(char), vars->max_len + 1);
		vars->i = 1;
	}
}

void	ft_bin_oct(t_vars_s *vars, int sig)
{
	if (vars->i > 128)
	{
		vars->i = 1;
		vars->len++;
	}
	if (sig == SIGUSR1)
		vars->str[vars->len] += vars->i;
	vars->i *= 2;
}

void	ft_receive(int sig, siginfo_t *info, void *context)
{
	static t_vars_s	*vars;

	if (!vars)
	{
		vars = (t_vars_s *) ft_calloc (sizeof(t_vars_s), 1);
		vars->i = 1;
	}
	else if (!vars->str)
		ft_bin_len(vars, sig);
	else
		ft_bin_oct(vars, sig);
	if (vars->len == vars->max_len - 1 && vars->i > 128)
	{
		kill(info->si_pid, SIGUSR2);
		ft_free_all(vars);
		vars = NULL;
	}
	if (vars)
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	signal;

	signal.sa_sigaction = ft_receive;
//	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_SIGINFO;
	ft_printf("Server PID :%d\n", getpid());
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
		pause();
	return (0);
}
