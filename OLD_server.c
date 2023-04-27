/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:23:04 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/26 19:17:00 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_vars		*vars;

void    ft_print_octet(unsigned char octet) //debug
{
        int     i;

        i = 1;
        while (i <= 255)
        {
                if (octet & i)
                        ft_printf("1");
                else
                        ft_printf("0");
                i *= 2;
        }
}

void	ft_receive(int sig)
{
//	ft_printf("Start\n");
//	ft_printf("PID: %d\n sig : %d\n vars->i :%d\n", vars->pid, sig, vars->i);
	if (!vars->str)
	{
//		ft_printf("vars->str\n");
		if (vars->i <= 2147483648)
		{
			if (sig == 10)
				vars->max_len += vars->i;
			vars->i *= 2;
		}
		else
		{
//			ft_printf("alloc\n");
			vars->i = 1;
			vars->str = (unsigned char *) calloc(sizeof(unsigned char), vars->max_len + 1);
			if (!vars->str)
				exit(ft_printf("Mem error\n"));
		}
	}
	else
	{
//		ft_printf("passed else\n");
		if (vars->i <= 255)
		{
			if (sig == 10)
				vars->str[vars->len] += vars->i;
			vars->i *= 2;
		}
		else if (vars->i > 255)
		{
//			ft_printf("first octet %i\n", vars->str[0]);
//			ft_print_octet(vars->str[vars->len]);
			vars->i = 1;
			vars->len++;
			if (sig == 10)
				vars->str[vars->len] += vars->i;
			vars->i *= 2;
		}
	}
//	ft_printf("vars->len :%d\n", vars->len);
//	ft_printf("vars->str :%s\n", vars->str);
}

int	main(void)
{
	vars = (t_vars *) calloc(sizeof(t_vars), 1);
	if (!vars)
		exit(ft_printf("Mem error\n"));
	vars->i = 1;
	vars->pid = getpid();
	ft_printf("PID :%d\n", vars->pid);
//	ft_print_octet('0');
	signal(SIGUSR1, ft_receive);
	signal(SIGUSR2, ft_receive);
	while (1)
	{
//		ft_printf ("Server up at PID: %d\n", pid);
//		ft_printf("len :%d\n", vars->len);
//		ft_printf("str:%s\nvars->len:%d vars->len_max:%d, vars->i%d\n", vars->str, vars->len, vars->max_len, vars->i);
		usleep(1000000);
		if (vars->len == vars->max_len - 1 && vars->i == 256)
		{
			ft_printf("%s\n", vars->str);
			free (vars->str);
			vars->str = NULL;
			vars->max_len = 0;
			vars->len = 0;
			vars->i = 1;
		}
	}
	return (0);
}
