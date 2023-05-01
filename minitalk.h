/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:23:59 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/01 15:29:32 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "Printf/ft_printf.h"
# include <string.h>
# include <signal.h>

typedef struct s_vars_s
{
	int					pid;
	unsigned int		len;
	unsigned int		max_len;
	unsigned long int	i;
	char				*str;
}			t_vars_s;

typedef struct s_vars_c
{
	int					pid;
	int					len_is_send;
	unsigned int		len;
	unsigned int		oct;
	unsigned long int	i;
	char				*str;
}			t_vars_c;

int		ft_atoi(const char *nptr);

size_t	ft_strlen(const char *str);

void	ft_free_all(t_vars_s *vars);

char	*ft_strdup(const char *s);

void	ft_send_len(int pid);
void	ft_send_str(int pid);
void	ft_bin_len(t_vars_s *vars, int sig);
void	ft_bin_oct(t_vars_s *vars, int sig);
void	ft_receive(int sig, siginfo_t *info, void *context);

void	*ft_calloc(size_t nmemb, size_t size);

#endif
