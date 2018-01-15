/* **************************************************************************** */
/*                                                                              */
/*                                                         :::      ::::::::    */
/*    malloc.h                                           :+:      :+:    :+:    */
/*                                                     +:+ +:+         +:+      */
/*    By: csellier <csellier@student.42.fr>          +#+  +:+       +#+         */
/*                                                 +#+#+#+#+#+   +#+            */
/*    Created: 2017/09/19 08:28:40 by csellier          #+#    #+#              */
/*    Updated: 2017/09/19 08:28:46 by csellier         ###   ########.fr        */
/*                                                                              */
/* **************************************************************************** */
#include <stdlib.h>
#include <sys/mman.h>
#include "libft/libft.h"

// pour memcpy
#include <string.h>


# define META_HEAD_SIZE sizeof(t_head)
# define META_SIZE sizeof(t_list_heap)
# define TNY 8
# define TINY 8 + META_SIZE
# define TINY_MAX TINY * 100 * getpagesize()
# define SML 1024
# define SMALL 1024 + META_SIZE
# define SMALL_MAX SMALL * 100 * getpagesize()
# define DEBUG write(2, "SALUT\n", 6);

/*
** free == 1 == is free
*/
typedef struct         s_list_heap
{
  int                  free;
  struct s_list_heap   *next;
}                      t_list_heap;

typedef struct         s_head
{
  size_t               size;
  struct s_list_heap   *tiny;
  struct s_list_heap   *small;
}                      t_head;

/*
** Global var == dynamic lib
*/
extern t_head			*head;

/*
** TODO
** # define TINY 1000
** # define MEDIUM 100000
** # define LARGE 1000000
**
** void					show_alloc_mem();
*/

void                   show_alloc_mem();
void					         *malloc(size_t size);
void					         free(void *ptr);
void					         *realloc(void *ptr, size_t size);
