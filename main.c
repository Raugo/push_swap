/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:59:44 by josuna-t          #+#    #+#             */
/*   Updated: 2021/12/21 17:06:55 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>

int	checklist(t_list *list, int count, int value)
{
	t_list	*mylist;

	mylist = list;
	while (mylist != 0)
	{
		if (value == (int)(long)mylist->content)
			return (0);
		mylist = mylist->next;
	}
	return (1);
}

int	checkargs(int argc, char **argv)
{
	int		count;
	int		check;
	int		index;

	count = 1;
	check = 0;
	index = 0;
	while (count < argc)
	{
		while (argv[count][index] != 0)
			check += ft_isdigit(argv[count][index++]);
		if (index != check)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		count++;
		index = 0;
		check = 0;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		count;
	t_list	*mylist;
	t_list	*addlist;
	int		tempint;

	if (checkargs(argc, argv))
		return (1);
	count = 1;
	while (count < argc)
	{
		if (count == 1)
			mylist = ft_lstnew((void*)(long)ft_atoi(argv[count]));
		else
		{
			if (checklist(mylist, count, ft_atoi(argv[count])))
			{
				addlist = ft_lstnew((void*)(long)ft_atoi(argv[count]));
				ft_lstadd_back(&mylist, addlist);
			}
			else
				return (1);
		}	
		count++;
	}
	printf("Valor del primer elemento %d", (int)(long)mylist->content);
}
