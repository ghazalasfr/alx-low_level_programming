#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
  * delete_nodeint_at_index - to delete node
  * @head: the head
  * @index: index
  *
  * Return: -1 failed 1 succeed
  */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *liste;
	listint_t *tmp;

	unsigned int i = 0;

	list = *head;

	if (*head == NULL || head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(liste);
		return (1);
	}

	while (liste)
	{
		if (i == index - 1)
		{
			tmp = liste->next;

			if (tmp == NULL)
				return (-1);

			liste->next = tmp->next;
			free(tmp);
			return (1);
		}

		i++;
		liste = liste->next;
	}

	return (-1);
}
