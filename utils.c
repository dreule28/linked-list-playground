#include "linkedlist.h"

void print_vals(t_node *head)
{
	t_node	*curr;

	//starting from the head until the last node
	curr = head;
	while (curr != NULL)
	{
		printf("Curr: %p\n", curr);
		printf("Value: %d\n", curr->value);
		printf("Prev: %p\n", curr->prev);
		printf("Next: %p\n\n", curr->next);
		curr = curr->next;
	}
	printf("\n\n\n");
}