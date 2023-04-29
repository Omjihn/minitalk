/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:09:10 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/29 17:31:41 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	ft_test(int sig)
{
	printf("%d\n", sig);
//	printf("%d\n", info->si_pid);
}

int	main(void)
{
	struct sigaction	test;

	test.sa_handler = &ft_test;
	printf("PID :%d\n", getpid());
	sigaction(SIGUSR1, &test, NULL);
	sigaction(SIGUSR2, &test, NULL);
	pause();
}
