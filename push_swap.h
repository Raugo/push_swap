/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:52:21 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/18 17:49:58 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

void	ft_sab(t_list **list, char letter);
void	ft_rab(t_list **list, char letter);
void	ft_pab(t_list **list1, t_list **list2, char letter);
void	ft_rrab(t_list **list, char letter);
void	orderlist(t_list *list, int argc);
int		checkorder(t_list *list);
void	exnumbers(t_list **list, t_list *mylist, int argc, t_list **listb);
int		checkorder(t_list *list);
#endif