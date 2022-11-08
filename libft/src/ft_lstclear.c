/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:14:56 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/09/26 18:47:31 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;

	if (!del)
		return ;
	while (*lst != NULL)
	{
		del((*lst)->content);
		cur = *lst;
		*lst = cur->next;
		free(cur);
	}
	*lst = NULL;
}
