/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_mandatory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:04:00 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/29 16:57:09 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_vars_s	*ft_free_all(t_vars_s *vars)
{
	ft_printf("%s\n", vars->str);
	free (vars->str);
	free (vars);
	return (NULL);
}

void	ft_bin_len(t_vars_s *vars, int sig)
{
	if (vars->i <= 2147483648)
	{
		if (sig == 10)
			vars->max_len += vars->i;
		vars->i *= 2;
	}
	else
	{
		vars->str = (char *) calloc (sizeof(char), vars->max_len + 1);
		vars->i = 1;
	}
}

void	ft_bin_oct(t_vars_s *vars, int sig)
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
}

void	ft_receive(int sig)
{
	static t_vars_s	*vars;

	if (!vars)
	{
		vars = (t_vars_s *) calloc (sizeof(t_vars_s), 1);
		vars->i = 1;
	}
	if (!vars->str)
		ft_bin_len(vars, sig);
	else if (vars->len == vars->max_len - 1 && vars->i > 128)
		vars = ft_free_all(vars);
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
		pause();
	return (0);
}
