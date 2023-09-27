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

	listint_t *prev = NULL;
	listint_t *curr = *head;
	listint_t *next = NULL;
	while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
    return (listint_t);
}
