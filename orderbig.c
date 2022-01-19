/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderbig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:54:45 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/19 18:05:14 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_delcontent(void *content)
{
	content = 0;
	return ;
}

void	orderbig(t_list **list, t_list **listb, int argc, t_list *mylist)
{
	t_list	*mylistb;
	int		index;
	int		num;

	mylist = *list;
	mylistb = *listb;
	index = 0;
	while (!checkorder(mylist))
	{
		num = 0;
		while (num < argc - 1)
		{
			if ((int)mylist->content & (1 << index))
				ft_rab(&mylist, 'a');
			else
				ft_pab(&mylist, &mylistb, 'b');
			num++;
		}
		while (mylistb != 0)
		{
			ft_pab(&mylistb, &mylist, 'a');
		}
		index++;
	}
	ft_lstclear(&mylist, &ft_delcontent);
}

void	exnumbers(t_list **list, t_list *mylist, int argc, t_list **listb)
{
	t_list	*mylist2;
	t_list	*mylist3;
	t_list	*addlist;
	t_list	*returnlist;

	mylist = *list;
	mylist3 = ft_lstnew((void *)(long)0);
	returnlist = mylist3;
	while (mylist != 0)
	{
		mylist2 = *list;
		while (mylist2 != 0)
		{
			if ((intptr_t)mylist2->content < (intptr_t)mylist->content)
				mylist3->content++;
			mylist2 = mylist2->next;
		}
		mylist = mylist->next;
		if (mylist == 0)
			break ;
		addlist = ft_lstnew((void *)(int)0);
		ft_lstadd_back(&mylist3, addlist);
		mylist3 = mylist3->next;
	}
	orderbig(&returnlist, listb, argc, mylist);
}
