/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:59:44 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/19 18:08:10 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

int	checklist(t_list *list, int value)
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

int	checkconversion(char *numc, int numi)
{
	int	index;

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
	if (numi == 0)
		index++;
	while (numi != 0)
	{
		numi = numi / 10;
		index++;
	}
	if (index == (int)ft_strlen(numc))
		return (0);
	return (1);
}

void	checkargs(int argc, char **argv)
{
	int		cnt;
	t_list	*mylist;
	t_list	*addlist;
	t_list	*listb;

	listb = 0;
	cnt = 1;
	mylist = ft_lstnew((void *)(intptr_t)ft_atoi(argv[0]));
	while (cnt < argc)
	{
		if (checklist(mylist, ft_atoi(argv[cnt])))
		{
			addlist = ft_lstnew((void *)(intptr_t)ft_atoi(argv[cnt++]));
			ft_lstadd_back(&mylist, addlist);
		}
		else
		{
			write(1, "Error\n", 6);
			ft_lstclear(&mylist, ft_delcontent);
			return ;
		}
	}
	orderlist(mylist, listb, argc);
}

int	convertargs(int argc, char **argv)
{
	int		count;
	int		*nums;

	if (argc <= 0)
		exit(0);
	count = 0;
	nums = malloc(argc * sizeof(int));
	while (count < argc)
	{
		nums[count] = ft_atoi(argv[count]);
		if (checkconversion(argv[count], nums[count]))
		{
			free(nums);
			return (1);
		}
		count++;
	}
	free(nums);
	if (argc > 1)
	{
		checkargs(argc, argv);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	**args;
	int		index;
	int		returnconvert;

	if (argc == 2)
	{
		index = 0;
		args = ft_split(argv[1], ' ');
		while (args[index] != 0)
		{
			index++;
		}
		argc = index;
		returnconvert = convertargs(argc, args);
		index = 0;
	}
	else
		returnconvert = convertargs(--argc, ++argv);
	if (returnconvert == 1)
		write(1, "Error\n", 6);
}
