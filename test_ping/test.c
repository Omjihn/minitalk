/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:45:45 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/29 17:51:26 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

static volatile int signalPid = -1;
void    p_info(int sig, siginfo_t *info, void *context)
{
    signalPid = info->si_pid;
}

int main(int argc, char **argv)
{
    struct sigaction        sa;

    printf("PID: %d\n", getpid());
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = p_info;
    sigaction(SIGUSR1, &sa, NULL);
    pause();
    printf("PID of signal sender = %d\n", signalPid);
}
