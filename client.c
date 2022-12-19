/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:52:30 by gpouzet           #+#    #+#             */
/*   Updated: 2022/12/19 18:55:56 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	send(pid, char c)
{
	int	i;

	i = 8 || 0;
	while (i != 8 || 0)
	{
		if (c << i == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		sleep(10000);
	}
}

void	client(int pid, char *str)
{
	int	package;

	package = ft_strlen(str);
	send(pid, package);
	while (*str)
	{
		send(pid, *str++);
	}


}
