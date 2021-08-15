/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 22:03:47 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/15 23:29:37 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	sendc(char c, int pid)
{
	sendb(!!(c & 0x01), pid);
	sendb(!!(c & 0x02), pid);
	sendb(!!(c & 0x04), pid);
	sendb(!!(c & 0x08), pid);
	sendb(!!(c & 0x10), pid);
	sendb(!!(c & 0x20), pid);
	sendb(!!(c & 0x40), pid);
	sendb(!!(c & 0x80), pid);
}

void	senda(char *c, int pid, int len)
{
	while (len--)
	{
		sendc(*c, pid);
		c++;
	}
}

void	sendi(int i, int pid)
{
	int	size;

	size = 8 * sizeof(int);
	while (size--)
	{
		sendb(i & 1, pid);
		i = i >> 1;
	}
}
