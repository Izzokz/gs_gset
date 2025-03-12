/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gs_gset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:15:35 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/03/11 16:15:36 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gs_gset.h"

static unsigned char	gs_gs_init(uintptr_t *(*vars)[2], unsigned char nmemb)
{
	int	i;

	free(**vars);
	if (*(*vars + 1))
	{
		i = -1;
		while (*(void **)(*(*vars + 1) + ++i))
			free(*(void **)(*(*vars + 1) + i));
	}
	free(*(*vars + 1));
	if (!nmemb)
		return (0);
	**vars = malloc((nmemb + 1) * sizeof(uintptr_t *));
	if (!**vars)
		return (0);
	*(*vars + 1) = malloc((nmemb + 1) * sizeof(uintptr_t *));
	if (!*(*vars + 1))
	{
		free(**vars);
		return (0);
	}
	gs_ft_bzero((uintptr_t)**vars, (nmemb + 1) * sizeof(uintptr_t *));
	gs_ft_bzero((uintptr_t)(*(*vars + 1)), (nmemb + 1) * sizeof(uintptr_t *));
	return (nmemb);
}

static uintptr_t	gs(unsigned char init, uintptr_t set, char *name)
{
	static uintptr_t	*vars[2] = {NULL, NULL};
	unsigned char		len;

	if (init == 1)
	{
		len = gs_gs_init(&vars, set);
		if (!len)
			gs_ft_bzero((uintptr_t)vars, 2);
		return (len);
	}
	if (!*vars || !name)
		return (0);
	len = -1;
	while (*(*(vars + 1) + ++len))
		if (gs_ft_sequals(name, *(char **)(*(vars + 1) + len)))
			break ;
	if (set)
	{
		if (!*(*(vars + 1) + len))
			*(*(vars + 1) + len) = (uintptr_t)gs_ft_strdup(name);
		if (!*(*(vars + 1) + len))
			return (gs(1, 0, 0));
		*(*vars + len) = set;
	}
	return (*(*vars + len));
}

/*
gs_ft_assign must be used before and after every operation.
gs_ft_assign will initialize and terminate.
gs_ft_assign(0) will free everything and return 0.
gs_ft_assign(X<1-255>) will (free and) allocate memory for X instances.
Returns X or 0 on fail.
*/
unsigned char	gs_ft_assign(unsigned char nmemb)
{
	if (gs(1, nmemb, NULL))
		return (1);
	return (0);
}

/*
gs_ft_set should be used after gs_ft_assign.
gs_ft_set((void *)ptr, "s1") will set ptr as "s1".
gs_ft_set(0, "s2") won't do anything.
gs_ft_set(555, NULL) won't do anything.
gs_ft_set((char ***)WOW, "") will set WOW as "".
Possible malloc fails.
*/
unsigned char	gs_ft_set(uintptr_t var, char *name)
{
	if (gs(0, var, name))
		return (1);
	return (0);
}

/*
gs_ft_get should be used after gs_ft_set.
gs_ft_get(NULL) will return 0.
gs_ft_get(unexisting_assignment) will return 0.
gs_ft_get(existing_assignment) will return the assigned variable as a uintptr_t.
(t_typ *)gs_ft_get("typ0") will cast the stored uintptr_t into the desired type.
No fail possible.
*/
uintptr_t	gs_ft_get(char *name)
{
	return (gs(0, 0, name));
}
