/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:52:30 by gpouzet           #+#    #+#             */
/*   Updated: 2023/02/21 14:58:59 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <unistd.h>
#include "../libft/libft.h"

static void	wakeup(int sig)
{
	if (sig == SIGUSR1)
		;
}

static void	send(int pid, char c)
{
	int	i;

	signal(SIGUSR1, &wakeup);
	i = sizeof(char) * 8;
	while (i)
	{
		if (c & (1 << --i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(420);
	}
}

static void	pack(int pid, size_t c)
{
	int	i;

	signal(SIGUSR1, &wakeup);
	i = sizeof(size_t) * 8;
	while (i)
	{
		if (c & (1 << --i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(420);
	}
}

static void	client(int pid, char *str)
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
	signal(SIGUSR1, &wakeup);
	client(ft_atoi(argv[1]), argv[2]);
	if (sleep(42))
		ft_putstr_fd("\nMessage received.\n", 1);
	else
		ft_putstr_fd("\nError message lost.\n", 2);
	return (0);
}
