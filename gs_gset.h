/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gs_gset.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:15:42 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/03/11 16:15:46 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GS_GSET_H
# define GS_GSET_H

# include <stdint.h>
# include <stdlib.h>

//	---|gs_utils.c|---
char			gs_ft_sequals(char *s1, char *s2);
char			*gs_ft_strdup(char *str);
void			gs_ft_bzero(uintptr_t thing, unsigned char nmemb);

//	---|gs_gset.c|---
uintptr_t		gs_ft_get(char *assign);
unsigned char	gs_ft_assign(unsigned char nmemb);
unsigned char	gs_ft_set(uintptr_t var, char *assign);

#endif
