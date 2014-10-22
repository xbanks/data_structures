#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
} node ;

typedef struct LinkedList
{
	node *head;
	node *end;
	int links;
} LinkedList;



LinkedList *insert(LinkedList *List, int data);
LinkedList *remove(LinkedList *List, int data);
LinkedList *remove_by_link(LinkedList *List, int link);
void printLinkedList(LinkedList *List);
LinkedList *insert(LinkedList *List, int data);

#endif