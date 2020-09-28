#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int data;
	struct node* prev;
	struct  node* next;
}Node;
Node *head, *tail;

push(Node* head,int data)
{
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	Node* cur = head->next;
	while (cur != tail)
	{
		cur = cur->next;
	}
	Node* prev = cur->prev;
	prev->next = node;
	node->prev = prev;
	cur->prev = node;
	node->next = cur;
}
erase(Node* head)
{
	Node* cur = head->next;
	head->next = cur->next;
	Node* prev = head->next;
	prev->prev = head;
	free(cur);
}
show(Node* head)
{
	Node* cur = head->next;
	while (cur != tail)
	{
		printf("%d ", cur->data);
		cur = cur->next;

	}
}
freeall(Node* head)
{
	Node* fall = head->next;
	while (fall != NULL)
	{
		free(fall);
		fall = fall->next;
	}
}
main()
{
	head = malloc(sizeof(Node));
	tail = malloc(sizeof(Node));
	head->prev = head;
	head->next = tail;
	tail->prev = head;
	tail->next = tail;
	push(head, 1);
	push(head, 2);
	push(head, 3);
	push(head, 4);
	push(head, 5);
	erase(head);
	show(head);
	freeall(head);
}
