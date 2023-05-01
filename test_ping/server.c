/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:09:10 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/01 15:05:27 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
/*
void	ft_test(int sig, siginfo_t *info, void *context)
{
	printf("%d\n", sig);
	printf("%d\n", info->si_pid);
}

int	main(void)
{
	struct sigaction	test;

	test.sa_handler = ft_test;
	printf("PID :%d\n", getpid());
	sigaction(SIGUSR1, &test, NULL);
	sigaction(SIGUSR2, &test, NULL);
	pause();
	return (0);
}*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void ft_test(int sig, siginfo_t *info, void *context) {
    printf("Received signal %d from process %d\n", sig, info->si_pid);
}

int main() {
    struct sigaction test;
    printf("PID %d\n", getpid());
    test.sa_sigaction = ft_test; // Use sa_sigaction instead of sa_handler

    sigaction(SIGUSR1, &test, NULL);

    printf("Waiting for signal...\n");

    pause(); // Wait for signal

    return 0;
}

