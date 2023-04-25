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

# define INT_MAX 2147483647

# include "Printf/ft_printf.h"
# include <signal.h>	

typedef struct s_vars
{
	int	i;
	int	pid;
	int	len;
	char	*str;
}			t_vars;

#endif
