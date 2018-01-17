/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiso.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:13:53 by gficara           #+#    #+#             */
/*   Updated: 2017/12/19 15:13:55 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstiso(t_list *ptr, t_list *nxt, t_list **head)
{
	t_list	*new;

	if (!head)
		return (NULL);
	if (nxt == *head)
	{
		new = *head;
		*head = new->next;
		return (new);
	}
	new = ptr->next;
	ptr->next = nxt->next;
	return (new);
}
