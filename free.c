/* **************************************************************************** */
/*                                                                              */
/*                                                         :::      ::::::::    */
/*    free.c                                             :+:      :+:    :+:    */
/*                                                     +:+ +:+         +:+      */
/*    By: csellier <csellier@student.42.fr>          +#+  +:+       +#+         */
/*                                                 +#+#+#+#+#+   +#+            */
/*    Created: 2017/09/19 08:28:40 by csellier          #+#    #+#              */
/*    Updated: 2017/09/19 08:28:46 by csellier         ###   ########.fr        */
/*                                                                              */
/* **************************************************************************** */

#include "malloc.h"

void  show_alloc_mem()
{
  if (!head)
    return ;
  if (head->tiny)
  {
    write(1, "TINY : ", 7);
    ft_putstr("salut");
  }
}



/*
** Actually frees only if size is big enough
** to minimize syscall


void	free(void *ptr)
{
	t_link_heap	*meta;

	if (ptr == NULL || !ptr)
		return;
	meta = ptr - META_BLOCK_SIZE;
	//if meta->size >...
	//else if{
	meta->free = 1;
}
*/