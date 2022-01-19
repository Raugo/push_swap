/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:54:44 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/19 17:59:03 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include<stdio.h>

void	order3(t_list **list)
{
	t_list			*mylist;

	mylist = *list;
	if (checkorder(mylist))
		return ;
	if (mylist->next->next->content < mylist->next->content)
	{
		if (mylist->next->content > mylist->content)
		{
			ft_sab(&mylist, 'a');
			ft_rab(&mylist, 'a');
		}
		else
		{
			ft_rab(&mylist, 'a');
			ft_sab(&mylist, 'a');
		}
	}
	else if (mylist->next->next->content > mylist->content)
		ft_sab(&mylist, 'a');
	else if (mylist->content > mylist->next->content)
		ft_rab(&mylist, 'a');
	else
		ft_rrab(&mylist, 'a');
	*list = mylist;
}

void	order45(t_list **list, t_list **listb, t_list	*mlist, t_list *mlistb)
{
	if (mlistb->content < mlist->content)
		ft_pab(listb, list, 'a');
	else if (mlistb->content < mlist->next->content)
	{
		ft_rab(list, 'a');
		ft_pab(listb, list, 'a');
		ft_rrab(list, 'a');
	}
	else if (mlistb->content < mlist->next->next->content)
	{
		ft_rab(list, 'a');
		ft_rab(list, 'a');
		ft_pab(listb, list, 'a');
		ft_rrab(list, 'a');
		ft_rrab(list, 'a');
	}
	else
	{
		if (mlistb->content < mlist->next->next->next->content)
		{
			ft_rrab(list, 'a');
		}
		ft_pab(listb, list, 'a');
		ft_rab(list, 'a');
	}
}

int	checkorder(t_list *list)
{
	while (list->next != 0)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}

void	orderlist(t_list *list, t_list *listb, int argc)
{
	argc++;
	listb = 0;
	if (argc == 3)
	{
		if (list->content > list->next->content)
			ft_sab(&list, 'a');
	}
	if (argc == 4)
		order3(&list);
	if (argc == 6)
		ft_pab(&list, &listb, 'b');
	if (argc == 5 || argc == 6)
	{
		ft_pab(&list, &listb, 'b');
		order3(&list);
		order45(&list, &listb, list, listb);
	}
	if (argc == 6)
		order45(&list, &listb, list, listb);
	else if (argc > 6)
		exnumbers(&list, list, argc, &listb);
	ft_lstclear(&list, &ft_delcontent);
}
