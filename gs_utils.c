/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gs_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:23:03 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/03/11 19:23:04 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gs_gset.h"

char	gs_ft_sequals(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	i = -1;
	while (*(s1 + ++i) || *(s2 + i))
		if (*(s1 + i) != *(s2 + i))
			break ;
	return (*(s1 + i) == *(s2 + i));
}

char	*gs_ft_strdup(char *str)
{
	int		i;
	char	*dup;

	if (!str)
		return (NULL);
	i = -1;
	while (*(str + ++i))
		;
	dup = malloc(i + 1);
	if (!dup)
		return (NULL);
	i = -1;
	while (*(str + ++i))
		*(dup + i) = *(str + i);
	*(dup + i) = '\0';
	return (dup);
}

void	gs_ft_bzero(uintptr_t thing, unsigned char nmemb)
{
	unsigned char	i;

	if (!thing || !nmemb)
		return ;
	i = -1;
	while (++i < nmemb)
		*(char *)(thing + i) = 0;
}
