/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:17:56 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/15 23:57:10 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #define __USE_POSIX199309
// #define __USE_POSIX

#include <signal.h>

#include <unistd.h>
#include <stdlib.h>

#include "ft_stdio.h"
#include "ft_stdlib.h"

static int	rlen(char v, int *len)
{
	static int	a = 0;

	*len = *len | (v << a);
	a++;
	if (a == (sizeof(int) * 8))
	{
		a = 0;
		return (1);
	}
	return (0);
}

static int	rchar(char v, int *len, char **str)
{
	static char	*ret = NULL;
	static char	*curr = NULL;
	static int	a = 0;

	if (!ret)
	{
		ret = ft_calloc(sizeof(char), *len + 1);
		ret[*len] = '\0';
	}
	if (!curr)
		curr = ret;
	*curr = *curr | v << a++;
	if (a == 8)
		curr++;
	if (a == 8)
		a = 0;
	if (curr - ret == *len)
	{
		*str = ret;
		curr = NULL;
		ret = NULL;
		a = 0;
		*len = 0;
		return (0);
	}
	return (1);
}

void	proc(char v)
{
	static int	len = 0;
	char		*ret;
	static char	r = 0;

	ret = NULL;
	if (!r)
		r = rlen(v, &len);
	else
		r = rchar(v, &len, &ret);
	if (ret)
	{
		ft_putstr_fd(ret, STDOUT);
		free(ret);
	}
}

void	hsu(int sig, siginfo_t *si, void *uc)
{
	(void) uc;
	if (sig == SIGUSR1)
		proc(1);
	else
		proc(0);
	usleep(1);
	kill(si->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			ss;

	if (sigemptyset(&ss) == -1)
		return (1);
	ft_putnbr_fd(getpid(), STDOUT);
	ft_putstr_fd("\n", STDOUT);
	sa.sa_sigaction = hsu;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = ss;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
