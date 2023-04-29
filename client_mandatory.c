/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:04:08 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/29 16:37:14 by gbricot          ###   ########.fr       */
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
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i *= 2;
		usleep(500);
	}
	kill(pid, SIGUSR1);
	usleep(500);
}

void	ft_send_str(const char *str, int pid)
{
	int	i;
	int	oct;

	i = 1;
	oct = 0;
	while (str[oct])
	{
		if (i <= 128)
		{
			if (str[oct] & i)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i *= 2;
		}
		else
		{
			i = 1;
			oct++;
		}
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	int	len;
	int	pid;

	if (argc != 3)
		exit (ft_printf("Please enter a PID and your message\n"));
	pid = ft_atoi(argv[1]);
	len = ft_strlen(argv[2]);
	if (len == 0)
		exit (42);
	ft_send_len(len, pid);
	ft_send_str(argv[2], pid);
	kill(pid, SIGUSR1);
	return (0);
}
