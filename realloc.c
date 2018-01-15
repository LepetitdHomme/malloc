/* **************************************************************************** */
/*                                                                              */
/*                                                         :::      ::::::::    */
/*    realloc.c                                          :+:      :+:    :+:    */
/*                                                     +:+ +:+         +:+      */
/*    By: csellier <csellier@student.42.fr>          +#+  +:+       +#+         */
/*                                                 +#+#+#+#+#+   +#+            */
/*    Created: 2017/09/19 08:28:40 by csellier          #+#    #+#              */
/*    Updated: 2017/09/19 08:28:46 by csellier         ###   ########.fr        */
/*                                                                              */
/* **************************************************************************** */

#include "malloc.h"

void	*realloc(void *ptr, size_t size)
{
	t_link_heap	*link_meta;

	if (!ptr || ptr == NULL)
		return (malloc(size));
	link_meta = ptr - META_BLOCK_SIZE;
	if (link_meta->size >= size + META_BLOCK_SIZE)
		return (ptr);
	if ((ptr = malloc(size)) == NULL)
		return (NULL);
	//libft ??
	memcpy(ptr, link_meta + META_BLOCK_SIZE, size);
	free(link_meta + META_BLOCK_SIZE);
	return (ptr);
}
