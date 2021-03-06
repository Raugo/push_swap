/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:22:13 by josuna-t          #+#    #+#             */
/*   Updated: 2021/11/03 16:57:47 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int value)
{
	if (!((value > 64 && value < 91) || (value > 96 && value < 123)
			|| (value > 47 && value < 58)))
		return (0);
	return (1);
}
