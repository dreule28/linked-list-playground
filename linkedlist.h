#ifndef LINKEDLIST_H
# define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;


void print_vals(t_node *head);
void leaks(void);

#endif