/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:14:15 by gpouzet           #+#    #+#             */
/*   Updated: 2022/10/14 15:14:38 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	if (!s1 || !s2)
		return (ft_calloc(0, 0));
	join = ft_calloc(1, ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (malloc(0));
	ft_strlcpy(join, s1, ft_strlen(s1) + 1);
	ft_strlcat(join, s2, ft_strlen(s2) + ft_strlen(s1) + 1);
	return (join);
}
