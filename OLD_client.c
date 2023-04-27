/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:21:19 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/26 19:25:00 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	i = 0;
	result = 0;
	while (nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - 48;
		i++;
	}
	return (result * sign);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_send_len(int len, int pid)
{
	long int	i;

	i = 1;
	while (i <= 2147483648)
	{
		if (len & i)
		{
			kill(pid, SIGUSR1);
			ft_printf("1");
		}
		else
		{
			kill(pid, SIGUSR2);
			ft_printf("0");
		}
		i *= 2;
		usleep(1000);
	}
}

void	ft_send_octet(unsigned char octet, int pid)
{
	int	i;

	i = 1;
	while (i <= 128)
	{
		if (octet & i)
		{
			kill(pid, SIGUSR1);
			ft_printf("1"); //debug
		}
		else
		{
			kill(pid, SIGUSR2);
			ft_printf("0"); //debug
		}
		i *= 2;
		usleep(1000);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	len;
	int	i;

	if (argc != 3)
		return (ft_printf("Please enter a PID and your message\n"));
	pid = ft_atoi(argv[1]);
	len = ft_strlen(argv[2]);
	ft_printf("len :%d\n", len);
	ft_send_len(len, pid);
	kill(pid, SIGUSR1);
	usleep(1000);
	ft_printf("\n");
	i = 0;
	while (argv[2][i])
	{
		ft_send_octet(argv[2][i], pid);
		i++;
	}
	return (0);
}
