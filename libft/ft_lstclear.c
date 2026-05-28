/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 15:04:56 by snagasak          #+#    #+#             */
/*   Updated: 2026/05/12 17:18:28 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*all;
	t_list	*next;

	all = *lst;
	while (all != NULL)
	{
		next = all->next;
		del(all->content);
		free(all);
		all = next;
	}
	*lst = NULL;
}
