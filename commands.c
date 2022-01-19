/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:01:02 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/19 18:03:36 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include<stdio.h>
#include <unistd.h>

void	ft_sab(t_list **list, char letter)
{
	struct s_list	*temp;
	t_list			*mylist;

	mylist = *list;
	if (mylist->next != 0)
	{
		temp = mylist;
		mylist = mylist->next;
		temp->next = mylist->next;
		mylist->next = temp;
	}
	*list = mylist;
	write(1, "s", 1);
	write(1, &letter, 1);
	write(1, "\n", 1);
}

void	ft_pab(t_list **list1, t_list **list2, char letter)
{
	t_list			*mylist;
	t_list			*mylist2;
	t_list			*temp;

	mylist = *list1;
	mylist2 = *list2;
	if (mylist != 0)
	{
		temp = mylist->next;
		if (mylist2 != 0)
			mylist->next = mylist2;
		else
			mylist->next = 0;
		*list1 = temp;
		*list2 = mylist;
	}
	write(1, "p", 1);
	write(1, &letter, 1);
	write(1, "\n", 1);
}

void	ft_rab(t_list **list, char letter)
{
	struct s_list	*temp;
	t_list			*mylist;

	mylist = *list;
	if (mylist->next != 0)
	{
		temp = mylist;
		mylist = mylist->next;
		temp->next = 0;
		ft_lstadd_back(&mylist, temp);
	}
	*list = mylist;
	write(1, "r", 1);
	write(1, &letter, 1);
	write(1, "\n", 1);
}

void	ft_rrab(t_list **list, char letter)
{
	t_list			*mylist;
	struct s_list	*temp;
	struct s_list	*temp2;

	mylist = *list;
	if (mylist->next != 0)
	{
		temp = mylist;
		while (temp->next->next)
		{
			temp = temp->next;
		}
		temp2 = temp->next;
		temp->next = 0;
		ft_lstadd_front(&mylist, temp2);
		*list = mylist;
	}
	write(1, "rr", 2);
	write(1, &letter, 1);
	write(1, "\n", 1);
}
