/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:25:04 by gpouzet           #+#    #+#             */
/*   Updated: 2022/10/12 14:00:26 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char	*tmp;

	tmp = (char *)src;
	while (size-- > 1 && *tmp)
		*dest++ = *tmp++;
	if (size == 0 || !*tmp)
		*dest = '\0';
	return (ft_strlen(src));
}
