/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:45:16 by allera-m          #+#    #+#             */
/*   Updated: 2023/03/09 07:53:08 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = s;
	while ((size_t)i < n)
	{
		s2[i] = '\0';
		i++;
	}
}