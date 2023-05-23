#include "sort.h"

/**
 * insertion_sort - sorts a doubly linked list of integers in
 *                  ascending order using the Insertion sort algorithm
 * @list: head of the doubly linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp1, *tmp2;
	int i, j;

	if (list == NULL)
		return;

	tmp1 = *list;

	for (i = 0; tmp1 != NULL; i++)
	{
		tmp2 = tmp1;
		for (j = i; j > 0; j--)
		{
			if (tmp2->n < tmp2->prev->n)
			{
				insert_node(list, tmp1, j);
				print_list(*list);
			}
			tmp2 = tmp2->prev;
		}
		tmp1 = tmp1->next;
	}
}

/**
* insert_node - inserts a  node in a given position
* @list: head of the doubly linked list
* @node: pointer to the node to be inserted at index
* @index: index where the node will be inserted
*
* Return: void
*/
void insert_node(listint_t **list, listint_t *node, unsigned int index)
{
	listint_t *tmp;
	unsigned int i;

	tmp = *list;
	for (i = 0; i < index; i++)
	{
		tmp = tmp->next;
		if (tmp == NULL)
			return;
	}
	if (node->next != NULL)
		node->next->prev = node->prev;
	if (node->prev != NULL)
		node->prev->next = node->next;
	if (tmp->prev != NULL)
	{
		tmp->prev->next = node;
		node->prev = tmp->prev;
	}
	else
	{
		node->prev = NULL;
	}
	node->next = tmp;
	tmp->prev = node;
}
