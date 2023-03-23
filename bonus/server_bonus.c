/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:56:06 by gpouzet           #+#    #+#             */
/*   Updated: 2023/02/21 15:38:43 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <signal.h>
#include "../libft/libft.h"
#include "../libft/printf/ft_printf.h"

static int	prout(char *str, char c)
{	
	str[ft_strlen(str)] = c;
	return (0);
}

static void	serv(int sig, siginfo_t *si, void *dc)
{
	static size_t	request = 0;
	static size_t	size = 0;
	static char		*str;
	static char		c = 0;
	int				cal;

	if (request++ < sizeof(size_t) * 8)
		size = size * 2 + (sig == SIGUSR1);
	else
		c = c * 2 + (sig == SIGUSR1);
	if (request == sizeof(size_t) * 8)
		str = ft_calloc((int)size + 1, 1);
	cal = (request - (sizeof(size_t) * 8));
	if (request > (sizeof(size_t) * 8) && !(cal % 8))
		c = prout(str, c);
	if (request > (sizeof(size_t) * 8) && (int)(size - cal / 8) == 0)
	{
		size = 0;
		request = 0;
		ft_putstr_fd(str, 1);
		free(str);
		usleep(500);
		kill(si->si_pid, SIGUSR1);
	}
	usleep(500);
	kill(si->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("%d\n", getpid());
	sig.sa_sigaction = serv;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		;
}
