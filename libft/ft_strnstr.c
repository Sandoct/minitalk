/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:56:00 by gpouzet           #+#    #+#             */
/*   Updated: 2022/10/12 13:53:56 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (!*little)
		return ((char *)big);
	while (len-- && *big)
		if (!ft_strncmp(big++, little, ft_strlen(little)))
			if (len + 1 >= ft_strlen(little))
				return ((char *)--big);
	return (0);
}
