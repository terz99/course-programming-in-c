/*
JTSK-320112
a6 p2.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

/**
 * @file queue.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

static void copy_to_node(Item item, Node *pn);
static void copy_to_item(Node *pn, Item *pi);

void initialize_queue(Queue *pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

int queue_is_full(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}

int queue_is_empty(const Queue *pq)
{
	return pq->items == 0;
}

int queue_item_count(const Queue *pq)
{
	return pq->items;
}

int enqueue(Item item, Queue *pq)
{
    if(queue_is_full(pq)){
        // queue overflow
        return -1;
    }

    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        // bad alloc
        return -1;
    }
    copy_to_node(item, new_node);
    new_node->next = NULL;

    if(queue_is_empty(pq)){
        pq->front = new_node;
        pq->rear = pq->front;
    } else {
        pq->rear->next = new_node;
        pq->rear = pq->rear->next;
    }

    pq->items++;

    return 0;
}

int dequeue(Item *pitem, Queue *pq)
{
	if(queue_is_empty(pq)){
        // queue underflow
        return -1;
    }

    copy_to_item(pq->front, pitem);
    
    Node *tmp = pq->front;
    pq->front = pq->front->next;
    free(tmp);
    pq->items--;

    if(pq->items == 0){
        pq->front = pq->rear = NULL;
    }

    return 0;
}

void empty_queue(Queue *pq)
{
	Item dummy;
	while (!queue_is_empty(pq)) {
		dequeue(&dummy, pq);
	}
}

static void copy_to_node(Item item, Node *pn)
{
	pn->item = item;
}

static void copy_to_item(Node *pn, Item *pi)
{
	*pi = pn->item;
}