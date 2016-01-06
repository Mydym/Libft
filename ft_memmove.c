/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:38:40 by vgrenier          #+#    #+#             */
/*   Updated: 2015/12/06 20:49:14 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*s1;
	const char			*s2;
	char				*stamp;
	size_t				i;

	s1 = (unsigned char *)dst;
	s2 = (const char *)src;
	stamp = (char *)malloc((len + 1) * sizeof(*stamp));
	i = 0;
	ft_strncpy(stamp, s2, len);
	stamp[len + 1] = '\0';
	while (i < len)
	{
		s1[i] = (unsigned char)stamp[i];
		i++;
	}
	free(stamp);
	return (dst);
}
