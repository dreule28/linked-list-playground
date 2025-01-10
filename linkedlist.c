#include "linkedlist.h"

void init(t_node **head, t_node **tail, int value)
{
	t_node *new_node = malloc(sizeof(t_node));

	if (!new_node)
	{
		exit(1);
		return ;
	}
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	*head = new_node;
	*tail = new_node;
}

void insert_beginning(t_node **head, int value)
{
	t_node *new_node = malloc(sizeof(t_node));

	if (!new_node)
	{
		exit(1);
		return ;
	}
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}
	*head = new_node;
}

void insert_ending(t_node **tail, int value)
{
	t_node *new_node = malloc(sizeof(t_node));

	if (!new_node)
	{
		exit(2);
		return ;
	}
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = *tail;
	(*tail)->next = new_node;
	*tail = new_node;
}

void deallocate(t_node **head, t_node **tail)
{
	if (*head == NULL)
	{
		return ;
	}
	t_node	*curr = *head;

	while(curr->next != NULL)
	{
		curr = curr->next;
		free(curr->prev);
	}
	free(curr);
	*tail = NULL;
	*head = NULL;
}

int	main(void)
{
	t_node	*head = NULL;
	t_node *tail = NULL;

	atexit(leaks);
	init(&head, &tail, 7);
	insert_beginning(&head, 3);
	insert_beginning(&head, 1);
	insert_ending(&tail, 4);
	print_vals(head);
	deallocate(&head, &tail);
	return (0);
}
