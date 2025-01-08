#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

void leaks(void)
{
	system("leaks test");
}

void deallocate(t_node *head)
{
	t_node	*curr;

	curr = head;
	if (head == NULL)
	{
		return ;
	}
	while(curr->next != NULL)
	{
	printf("Freening node at adress: %p\n", curr);
		curr = curr->next;
		free(curr->prev);
	}
	free(curr);
}

int	main(void)
{
	t_node	*head;
	t_node	*tail;
	t_node	*curr;

	atexit(leaks);
	//initializing each node
	head = malloc(sizeof(t_node));
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


	//starting from the head until the last node
	printf("\nStarting from head:\n\n");
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

	//starting from the tail until the first ndoe
	// printf("Starting from tail:\n\n");
	// curr = tail;
	// while (curr != NULL)
	// {
	// 	printf("Curr: %p\n", curr);
	// 	printf("Value: %d\n", curr->value);
	// 	printf("Prev: %p\n", curr->prev);
	// 	printf("Next: %p\n\n", curr->next);
	// 	curr = curr->prev;
	// }
	deallocate(head);


	// printf("Node 1 --> curr: %p\n", head);
	// printf("Node 1 --> value: %d\n", head->value);
	// printf("Node 1 --> next: %p\n", head->next);
	// printf("Node 1 --> prev: %p\n", head->prev);
	// printf("Node 2 --> curr: %p\n", head->next);
	// printf("Node 2 --> value: %d\n", head->next->value);
	// printf("Node 2 --> next: %p\n", head->next->next);
	// printf("Node 2 --> prev: %p\n", head->next->prev);
	// printf("Node 3 --> curr: %p\n", head->next->next);
	// printf("Node 3 --> value: %d\n", head->next->next->value);
	// printf("Node 3 --> prev: %p\n", head->next->next->prev);
	// printf("Node 3 --> next: %p\n", head->next->next->next);
	return (0);
}
