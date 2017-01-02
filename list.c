#include "list.h"
#include<stdio.h>
#include<stdlib.h>

List * createList()
{
	List * new_list = malloc(sizeof(List));
	new_list->head = NULL;
	new_list->tail = NULL;
}

void insertData(List * list, int index, Data data)
{
	if (list->head == NULL && list->tail == NULL)
	{
		Node *node = malloc(sizeof(Node));
		node->data = data;
		node->next = NULL;
		node->prev = NULL;
		list->head = node;
		list->tail = node;
	}
	else {
		Node *current = list->head;
		int count = 0;
		if (index == 0)
		{
			Node *new_node = malloc(sizeof(Node));
			list->head->prev = new_node;
			new_node->next = list->head;
			new_node->prev = NULL;
			list->head = list->head->prev;
			list->head->data = data;
		}
		else
		{
			while (current != NULL && count < index)
			{
				if (count - 1 == index && current != list->tail)
				{
					Node *new_node = malloc(sizeof(Node));
					Node *old_node = current->next;
					new_node->next = old_node;
					new_node->prev = current;
					current->next = new_node;
					old_node->prev = new_node;
					new_node->data = data;
					break;
				}
				else if (count - 1 == index && current == list->tail)
				{
					list->tail->next = malloc(sizeof(Node));
					list->tail->next->data = data;
					list->tail->next->next = NULL;
					list->tail->next->prev = list->tail;
					list->tail = list->tail->next;
					break;
				}
				current = current->next;
				count++;
			}
			if (current == NULL)
			{
				list->tail->next = malloc(sizeof(Node));
				list->tail->next->data = data;
				list->tail->next->next = NULL;
				list->tail->next->prev = list->tail;
				list->tail = list->tail->next;
			}
		}
	}
}
Data * readData(List * list, int index)
{
	int count = 0;
	Node *current = list->head;
	while (current != NULL)
	{
		if (count == index)
		{
			return &current->data;
			break;
		}
		current = current->next;
		count++;
	}
	return NULL;
}


int searchForward(List * list, Data data)
{
	int count = 0;
	Node *current = list->head;
	while (current != NULL)
	{
		if (current->data.value == data.value)
			return count;
		current = current->next;
		count++;
	}
	return -1;
}
int searchBackward(List * list, Data data)
{
	int count = 0;
	Node *current = list->tail;
	while (current != NULL)
	{
		if (current->data.value == data.value)
			return count;
		current = current->prev;
		count++;
	}
	return -1;
}


void removeData(List *list, int index)
{
	int count = 0;
	Node *prev_node = NULL, *next_node = NULL;
	Node *current = NULL;
	if (index >= 0)
	{
		current = list->head;
		if (current == list->tail && list->tail != NULL)
		{
			free(list->head);
			list->head = NULL;
			list->tail = NULL;
		}
		else if (index == 0)
		{
			current = list->head->next;
			free(list->head);
			list->head = current;
			list->head->prev = NULL;
		}

		else
		{
			while (current != NULL && count < index)
			{
				current = current->next;
				count++;

			}
			if (index == count && current != list->tail)
			{
				next_node = current->next;
				prev_node = current->prev;
				free(current);
				current = NULL;
				prev_node->next = next_node;
				next_node->prev = prev_node;
			}
			else if (index == count && current == list->tail)
			{
				list->tail = current->prev;
				free(current);
				current = NULL;
				list->tail->next = NULL;
			}

		}
	}
	else
	{
		count = -1;
		current = list->tail;
		if (index == -1)
		{
			current = list->tail->prev;
			free(list->tail);
			list->tail = current;
			list->tail->next = NULL;
		}
		else
		{
			while (current != NULL && count > index)
			{
				current = current->prev;
				count--;
			}
			if (index == count)
			{
				Node *prev = current->prev;
				Node *next = current->next;
				free(current);
				current = NULL;
				prev->next = next;
				next->prev = prev;
			}
		}
	}
}

int isEmpty(List *list)
{
	if (list->head == NULL && list->tail == NULL)
		return 1;
	else return 0;
}
void deleteList(List * list)
{
	free(list);
}


void push(Stack * stack, Data data)
{
	insertData(stack->list, 0, data);

}


Data pop(Stack *stack)
{
	Data *d = readData(stack->list, 0);
	Data data = (Data){ d->value };
	removeData(stack->list, 0);
	return data;
}

Data * readTailData(List * list)
{
	if (list->tail != NULL){
		return &list->tail->data;
	}
	return NULL;
}

void removeTailData(List *list)
{
	if (list->tail != NULL && list->head == list->tail)
	{
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
	}
	else if (list->tail != NULL)
	{
		Node *current = list->tail;
		list->tail = list->tail->prev;
		free(current);
		current = NULL;
	}
}
void enqueue(Queue *queue, Data data)
{
	insertData(queue->list, 0, data);
	Data *d = readTailData(queue->list);
}
Data dequeue(Queue *queue)
{
	Data *d = readTailData(queue->list);
	Data data = (Data){ d->value };
	removeTailData(queue->list);
	return data;
}