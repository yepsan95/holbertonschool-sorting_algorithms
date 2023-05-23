#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 *                       ascending order using the Insertion sort algorithm
 * @list: head of the doubly linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *tmp;

	if (list == NULL)
		return;

	head = *list;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		while (tmp->prev != NULL)
		{
			if (tmp->prev->n > tmp->n)
			{
				swap_node(tmp->prev, tmp);
				if (tmp->prev == NULL)
					*list = tmp;
				print_list(*list);
			}
			else
			{
				tmp = tmp->prev;
			}
		}
	}
}

/**
* swap_node - swaps twoa adjacent nodes in a doubly linked list
* @node_a: pointer to the node previous to node_b
* @node_b: pointer to the node next to node_a
*
* Return: void
*/
void swap_node(listint_t *node_a, listint_t *node_b)
{
	if (node_a->prev != NULL)
	{
		node_a->prev->next = node_b;
		node_b->prev = node_a->prev;
	}
	else
	{
		node_b->prev = NULL;
	}
	if (node_b->next != NULL)
	{
		node_b->next->prev = node_a;
		node_a->next = node_b->next;
	}
	else
	{
		node_a->next = NULL;
	}
	node_a->prev = node_b;
	node_b->next = node_a;
}
