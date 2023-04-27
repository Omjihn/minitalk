/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:04:00 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/27 12:27:54 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_free_all(t_vars *vars)
{
	ft_printf("%s\n", vars->str);
	free (vars->str);
	free (vars);
}

void	ft_bin_len(t_vars *vars, int sig)
{
	if (vars->i <= 2147483648)
	{
		if (sig == 10)
			vars->max_len += vars->i;
		vars->i *= 2;
	}
	else
	{
		ft_printf("Alloc %d char\n", vars->max_len);
		vars->str = (char *) calloc (sizeof(char), vars->max_len + 1);
		vars->i = 1;
	}
}

void	ft_bin_oct(t_vars *vars, int sig)
{
	if (vars->i <= 128)
	{
		if (sig == 10)
			vars->str[vars->len] += vars->i;
		vars->i *= 2;
	}
	else if (vars->i > 128)
	{
		vars->i = 1;
		vars->len++;
		if (sig == 10)
                        vars->str[vars->len] += vars->i;
                vars->i *= 2;
	}
	ft_printf("%s\n", vars->str);
}

void	ft_receive(int sig)
{
	static t_vars	*vars;

	if (!vars)
	{
		vars = (t_vars *) calloc (sizeof(t_vars), 1);
		vars->i = 1;
	}
	else if (!vars->str)
		ft_bin_len(vars, sig);
	else if (vars->len == vars->max_len - 1 && vars->i > 128)
		ft_free_all(vars);
	else
		ft_bin_oct(vars, sig);
}

int	main(void)
{
	int pid;

	pid = getpid();
	ft_printf("Server PID :%d\n", pid);
	signal(SIGUSR1, ft_receive);
	signal(SIGUSR2, ft_receive);
	while (1)
	{

	}
	return (0);
}
