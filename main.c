/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:59:44 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/13 15:15:43 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>

void	ft_sab(t_list **list);
void	ft_pab(t_list **list1, t_list **list2);
void	ft_rrab(t_list **list);
void	orderlist(t_list *list, int argc);

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

int checkconversion(char* numc, int numi)
{
	int index;

	index = 0;
	if (numi < 0)
	{
		if (numc[0] == '-')
		{
			numc++;
			numi = -numi;
		}
		else
			return (1);
	}
	while (numi != 0)
	{
		numi = numi / 10;
		index++;
	}
	if (index == ft_strlen(numc))
		return (0);
	return (1);
}

int	convertargs(int argc, char **argv)
{
	int		count;
	int		*nums;

	count = 1;
	nums = malloc(argc * sizeof(int));
	while (count < argc)
	{
		nums[count] = ft_atoi(argv[count]);
		if (checkconversion(argv[count], nums[count]))
			return (1);
		count++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		count;
	t_list	*mylist;
	t_list	*addlist;

	if (convertargs(argc, argv))
		return (1);
	count = 1;
<<<<<<< HEAD
	if (argc >= 2)
=======
	if (argc > 2)
>>>>>>> 9425d3c808046d874fe57ad712cfa0713dd25d75
	{
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
<<<<<<< HEAD
			}
			count++;
		}
		orderlist(mylist, argc);
=======
			}	
			count++;
		}
>>>>>>> 9425d3c808046d874fe57ad712cfa0713dd25d75
	}
	else
		write(1, "Error\n", 6);
}
