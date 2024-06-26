/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:56:06 by gpouzet           #+#    #+#             */
/*   Updated: 2023/03/13 16:54:52 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"
#include "libft/printf/ft_printf.h"

void	serv(int sig)
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
	{
		str[ft_strlen(str)] = c;
		c = 0;
	}
	if (request > (sizeof(size_t) * 8) && (int)(size - (cal / 8)) == 0)
	{
		size = 0;
		request = 0;
		ft_putstr_fd(str, 1);
		free(str);
	}
}

int	main(void)
{
	signal(SIGUSR1, serv);
	signal(SIGUSR2, serv);
	ft_printf("%d\n", getpid());
	while (1)
		;
	return (0);
}
