/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:04:13 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/15 22:18:23 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

void	sendb(char c, int pid);
void	sendc(char c, int pid);
void	senda(char *c, int pid, int len);
void	sendi(int i, int pid);

#endif
