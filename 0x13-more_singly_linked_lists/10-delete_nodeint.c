#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
  * delete_nodeint_at_index - to delete node
  * @head: the head
  * @idx: index
  *
  * Return: listint_t
  */
int delete_nodeint_at_index(listint_t **head, unsigned int idx)
{
        listint_t *temp=head;
        int i;
        if (idx == 0) {
                head = head -> next;
                temp ->next = NULL;
                free(temp);
        }else {
        for (i = 0; i < idx - 1; i++) {
            temp = temp->next;
        }
         struct listint_t * del = temp->next;
        temp->next = temp->next->next;
        del->next = NULL;
        free(del);
        }
        return (NULL);
}
