#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

int	main(void)
{
	t_node *head;
	t_node *tail;

	head = malloc(sizeof(t_node));
	tail = malloc(sizeof(t_node));
	if (!head)
		return (1);
	head->value = 1;
	head->prev = NULL;
	head->next = malloc(sizeof(t_node));
	if (!head->next)
		return (1);
	head->next->value = 3;
	head->next->prev = head;
	head->next->next = malloc(sizeof(t_node));
	if (!head->next->next)
		return (1);
	head->next->next->value = 7;
	head->next->next->prev = head->next;
	head->next->next->next = NULL;
	tail = head->next->next;


	printf("Node 1 --> curr: %p\n", head);
	printf("Node 1 --> value: %d\n", head->value);
	printf("Node 1 --> next: %p\n", head->next);
	printf("Node 1 --> prev: %p\n", head->prev);
	printf("Node 2 --> curr: %p\n", head->next);
	printf("Node 2 --> value: %d\n", head->next->value);
	printf("Node 2 --> next: %p\n", head->next->next);
	printf("Node 2 --> prev: %p\n", head->next->prev);
	printf("Node 3 --> curr: %p\n", head->next->next);
	printf("Node 3 --> value: %d\n", head->next->next->value);
	printf("Node 3 --> prev: %p\n", head->next->next->prev);
	printf("Node 3 --> next: %p\n", head->next->next->next);
	return (0);
}