/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:47:06 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/22 09:54:56 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (*(unsigned char *)s1++ == *(unsigned char *)s2++ && n - 1)
		n--;
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/*
int	main(void)
{
	char	s1[] = "apple";
	char	s2[] = "apble";
	// char	c1 = (char)(1);
	// char	c2 = (char)(3);

	printf("%d\n", ft_strncmp(s1, s2, 0));
	// printf("%d, %d\n", c1, c2);
	// printf("%d, %d\n", (unsigned char)c1, (unsigned char)c2);
	// printf("%d\n", (unsigned char)c1 - (unsigned char)c2);
	// printf("%d\n", (c1 - c2));
	// printf("%d\n", (unsigned char)(c1 - c2));
}
*/