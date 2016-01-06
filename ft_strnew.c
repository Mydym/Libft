/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:52:44 by vgrenier          #+#    #+#             */
/*   Updated: 2015/12/06 20:41:06 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(size * sizeof(*str));
	if (str == NULL)
		return (NULL);
	i = 0;
	if (str)
	{
		while (i < size)
		{
			str[i] = 0;
			i++;
		}
	}
	return (str);
}
