/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:01:02 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/11 15:19:07 by josuna-t         ###   ########.fr       */
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
	write(1,"s",1);
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
	if (mylist->content != (void*)(unsigned long)2147483648)
	{
		temp = ft_lstnew(mylist->content);
		if (mylist->next != 0)
			mylist = mylist->next;
		else
			mylist->content = (void*)(unsigned long)2147483648;
		if (mylist2->content != (void*)(unsigned long)2147483648)
			temp->next = mylist2;
		else
			temp->next = 0;
		*list1 = mylist;
		*list2 = temp;
	}
	write(1,"p",1);
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
	write(1,"r",1);
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
	write(1,"rr",2);
	write(1, &letter, 1);
	write(1, "\n", 1);
}
