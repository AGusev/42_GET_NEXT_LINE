/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 21:45:11 by agusev            #+#    #+#             */
/*   Updated: 2019/02/18 21:56:03 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char *str)
{
	char *res;

	res = str;
	while (*str != '\0')
	{
		if (*str <= 'Z' && *str >= 'A')
			*str = *str + 32;
		str++;
	}
	return (res);
}
