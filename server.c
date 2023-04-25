/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:23:04 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/25 21:57:40 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_vars		*vars;

void	ft_receive(int sig)
{
	ft_printf("Start\n");
	ft_printf("PID: %d\n sig : %d\n vars->i :%d\n", vars->pid, sig, vars->i);
	if (vars->str == NULL)
	{
		ft_printf("vars->str\n");
		if (vars->i <= INT_MAX)
		{
			if (sig == 10)
				vars->len += vars->i;
			vars->i *= 2;
		}
		else
		{
			vars->i = 1;
			vars->str = (char *) calloc(sizeof(char), vars->len + 1);
			if (!vars->str)
				exit(ft_printf("Mem error\n"));
		}
	}
	/*else
	{
		ft_printf("passed else\n");
		if (vars->i <= 128)
		{
			if (sig == 10)
				vars->str[vars->len] += vars->i;
			vars->i *= 2;
		}
		else if (vars->i > 128)
		{
			vars->i = 1;
			vars->len--;
			if (sig == 10)
				vars->str[vars->len] += vars->i;
			vars->i *= 2;
		}
	}*/
	ft_printf("vars->len :%d\n", vars->len);
	ft_printf("vars->str :%s\n", vars->str);
}

int	main(void)
{
	vars = (t_vars *) calloc(sizeof(t_vars), 1);
	if (!vars)
		exit(ft_printf("Mem error\n"));
	vars->i = 1;
	vars->pid = getpid();
	ft_printf("PID :%d\n", vars->pid);
	signal(SIGUSR1, ft_receive);
	signal(SIGUSR2, ft_receive);
	while (1)
	{
//		ft_printf ("Server up at PID: %d\n", pid);
//		usleep(10000000);
	}
	return (0);
}
