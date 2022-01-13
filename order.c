/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:54:44 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/13 15:36:38 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>

void	order3(t_list **list)
{
	t_list			*mylist;

	mylist = *list;
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

void	order45(t_list **list, t_list **listb, t_list *mylist, int num)
{
	t_list	*mylistb;
	int		min;
	int		index;
	int		pos;

	index = 0;
	min = mylist->content;
	pos = 0;
	mylistb = *listb;
	while (mylist->next != 0)
	{
		index++;
		mylist = mylist->next;
		if (min < mylist->content)
		{
			min = mylist->content;

	}
}

int	checkorder(t_list *list)
{
	while (list->next !=0)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}

void	orderlist(t_list *list, int argc)
{
	t_list	*mylistb;

	if (checkorder(list))
		return ;
	mylistb = ft_lstnew((void*)(long)2147483647 + 1);
	if (argc == 3)
	{
		if (list->content > list->next->content)
			ft_sab(&list, 'a');
	}
	if (argc == 4)
		order3(&list);
	else if (argc == 5)
	{
		ft_pab(&list, &mylistb, 'b');
		order3(&list);
		order45(&list, &mylistb, list, 4);
	}
	else if (argc == 6)
	{
		ft_pab(&list, &mylistb, 'b');
		ft_pab(&list, &mylistb, 'b');
		order3(&list);
		order45(&list, &mylistb, list, 4);
		order45(&list, &mylistb, list, 5);
	}
}