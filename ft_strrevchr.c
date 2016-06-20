/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrevchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 17:54:56 by vgrenier          #+#    #+#             */
/*   Updated: 2016/03/17 15:25:43 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrevchr(char *s, int c)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	if (!s || !*s)
		return (NULL);
	str = ft_strnew(ft_strlen(s));
	if (!str)
		return (NULL);
	ft_bzero(str, ft_strlen(s));
	while (s[i] != '\0' && s[i] != (char)c)
	{
		str[i] = s[i];
		i++;
	}
	str[i + 1] = '\0';
	return (str);
}
