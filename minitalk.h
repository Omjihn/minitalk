/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:23:59 by gbricot           #+#    #+#             */
/*   Updated: 2023/04/22 16:31:42 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "Printf/ft_printf.h"
# include <signal.h>

typedef struct s_vars_s
{
	int	pid;
	unsigned long int	i;
	unsigned int	len;
	unsigned int	max_len;
	char	*str;
}			t_vars_s;

typedef struct s_vars_c
{
	int	pid;
	unsigned int	len;
	unsigned int	i;
	unsigned int	oct;
}			t_vars_c;
	

int		ft_strlen(const char *str);
int		ft_atoi(const char *nptr);

t_vars_s	*ft_free_all(t_vars_s *vars);

void	ft_send_len(int len, int pid);
void	ft_send_str(const char *str, int pid);
void	ft_bin_len(t_vars_s *vars, int sig);
void	ft_bin_oct(t_vars_s *vars, int sig);
void	ft_receive(int sig);

#endif
