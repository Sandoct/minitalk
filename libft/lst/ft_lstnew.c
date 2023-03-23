/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:26:44 by gpouzet           #+#    #+#             */
/*   Updated: 2022/11/07 17:33:23 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}
