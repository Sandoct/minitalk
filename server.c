/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:56:06 by gpouzet           #+#    #+#             */
/*   Updated: 2022/12/19 19:11:02 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	receive(void)
{
	char	c;
	int	i;

	i = 0;
	while (i != 8)
	{
		if (SIGUSR1)
			c += 1 << i++;
		else if (SIGUSR2)
			c += 0 << i++;
	}
	return ((char) c);
}

void	server()
{
	int	i;
	char	*str;

	i = ft_atoi(receive());

	while (1)
	{
		*str++ = receive();
		if (!(i--))
			break and return signal
	}
	ft_printf("%s", str);

}
