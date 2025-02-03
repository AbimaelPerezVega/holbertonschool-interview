#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse_listint - Reverses a linked list
 * @head: Pointer to the head of the list
 * Return: Pointer to the new head of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *current = *head, *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
	return (*head);
}

/**
 * find_middle - Finds the middle node of a linked list
 * @head: Pointer to the head of the list
 * Return: Middle node of the list
 */
listint_t *find_middle(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return (slow);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Pointer to the head of the list
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *middle, *second_half, *first_half;
	int is_pal = 1;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	middle = find_middle(*head);
	second_half = reverse_listint(&middle);

	first_half = *head;
	while (second_half != NULL)
	{
		if (first_half->n != second_half->n)
		{
			is_pal = 0;
			break;
		}
		first_half = first_half->next;
		second_half = second_half->next;
	}

	reverse_listint(&middle); /* Restore original list */
	return (is_pal);
}
