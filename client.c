/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:52:30 by gpouzet           #+#    #+#             */
/*   Updated: 2023/03/08 19:14:27 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

static void	send(int pid, char c)
{
	int	i;

	i = 8;
	while (i)
	{
		if (c & (1 << --i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

static void	pack(int pid, size_t c)
{
	int	i;

	i = sizeof(size_t) * 8;
	while (i)
	{
		if (c & (1 << --i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

void	client(int pid, char *str)
{
	size_t	package;

	package = ft_strlen(str);
	pack(pid, package);
	while (*str)
		send(pid, *str++);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	client(ft_atoi(argv[1]), argv[2]);
	return (0);
}
