#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * reverse_listint - reverse the list
  * @head: the head of the list
  *
  * Return: listint_t
  */

listint_t *reverse_listint(listint_t **head){

	listint_t *current=NULL;
	listint_t *previous=NULL;
	while (*head)
	{
		current = (*head)->next;
		(*head)->next = previous;
		previous = *head;
		*head = current;
	}

	*head = previous;

	return (*head);
}
