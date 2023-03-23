/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:24:29 by gpouzet           #+#    #+#             */
/*   Updated: 2022/10/12 13:56:52 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmpdest;
	unsigned char	*tmpsrc;

	tmpdest = (unsigned char *)dest;
	tmpsrc = (unsigned char *)src;
	if (!dest && !src)
		return (dest);
	while (n--)
		*tmpdest++ = *tmpsrc++;
	return (dest);
}
