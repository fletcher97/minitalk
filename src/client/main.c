/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:18:07 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/15 23:30:12 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_string.h"
#include "ft_ctype.h"

#include "client.h"

void	sendb(char c, int pid)
{
	if (c & 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	pause();
	usleep(1);
}

static int	check_pid(const char *str)
{
	while (*str && ft_isdigit(*str))
		str++;
	return (!*str);
}

static void	h(int s)
{
	if (s == SIGUSR2)
	{
		ft_putstr_fd("An error occured", 1);
		exit(3);
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
		return (1);
	if (!check_pid(argv[1]))
		return (2);
	pid = ft_atoi(argv[1]);
	ft_putstr_fd("Sending message to ", STDOUT);
	ft_putnbr_fd(pid, STDOUT);
	ft_putstr_fd("\nMessage: ", STDOUT);
	ft_putendl_fd(argv[2], STDOUT);
	signal(SIGUSR1, h);
	signal(SIGUSR2, h);
	sendi(ft_strlen(argv[2]), pid);
	senda(argv[2], pid, ft_strlen(argv[2]));
	return (0);
}
