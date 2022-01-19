/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:59:44 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/19 15:32:33 by josuna-t         ###   ########.fr       */
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

int	convertargs(int argc, char **argv)
{
	int		count;
	int		*nums;

	if (argc <= 1)
		exit(0);
	count = 1;
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
	return (0);
}

void	checkargs(int argc, char **argv)
{
	int		cnt;
	t_list	*mylist;
	t_list	*addlist;

	cnt = 2;
	mylist = ft_lstnew((void *)(intptr_t)ft_atoi(argv[1]));
	while (cnt < argc)
	{
		if (checklist(mylist, ft_atoi(argv[cnt])))
		{
			addlist = ft_lstnew((void *)(intptr_t)ft_atoi(argv[cnt++]));
			ft_lstadd_back(&mylist, addlist);
		}
		else
		{
			exit (1);
		}
	}
	orderlist(mylist, argc);
}

int	main(int argc, char **argv)
{
	char	**args;
	int		index;

	if (argc == 2)
	{
		index = 0;
		args = ft_split(argv[1], ' ');
		while (args[index] != 0)
		{
			argv[index + 1] = args[index];
			index++;
		}
		argc = ++index;
	}
	if (!convertargs(argc, argv))
	{
		if (argc > 2)
		{
			checkargs(argc, argv);
		}
		 char *str = "Hola buenos dias";
    char **matrix;
    size_t cnt;
    cnt = 0;
    //printf("%zu\n", nb_str);
    printf("\n STR inicial ( ' ' ): %s\n\n", str);
    matrix = ft_split(str, 0);
    while (matrix[cnt])
    {
        printf("STR %zu: %s\n", cnt, matrix[cnt]);
        cnt++;
    }
    system ("leaks push_swap");
    return (0);
		return (0);
	}
	write(1, "Error\n", 6);
}
