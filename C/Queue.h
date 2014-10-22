#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct DataNode
{
	char char_data;
	int int_data;
} DataNode;

typedef struct QueueNode
{
	DataNode *dataNode;
	struct QueueNode *next;
} QueueNode;

typedef struct Queue
{
	QueueNode *head;
	QueueNode *tail;
} Queue;

typedef enum { false, true } bool;

// Function prototypes
Queue *create_queue();
Queue *clear_queue(Queue *queue);
Queue *enqueue(Queue *queue, QueueNode *queueNode);
Queue *simple_enqueue(Queue *queue, char c, int i);
QueueNode *create_queue_node();
QueueNode *dequeue();
QueueNode *peek(Queue *queue);
void clear_node(QueueNode *queueNode);
void print_queue(Queue *queue);
void print_queue_helper(QueueNode *queueNode);
void print_queue_node(QueueNode *queueNode);
int isEmpty(Queue *queue);

// Creating and Deletion Methods
Queue *create_queue(Queue *queue)
{
	if(queue != NULL)
	{
		printf("ERR: Overwrite\n");
		return queue;
	}

	Queue *newQueue = malloc(sizeof(Queue) * 1);
	if(newQueue == NULL)
		return NULL;

	newQueue->head = newQueue->tail = NULL;

	return newQueue;
}

Queue *clear_queue(Queue *queue)
{
	if(queue == NULL)
		return NULL;
	QueueNode *queueNode;

	while(queue->head != NULL)
	{
		queueNode = dequeue(queue);
		clear_node(queueNode);
	}

	free(queue);
	return NULL;
}

void clear_node(QueueNode *queueNode)
{
	free(queueNode->dataNode);
	free(queueNode);
}

QueueNode *create_queue_node()
{
	QueueNode *queueNode = malloc(sizeof(QueueNode) * 1);
	if(queueNode == NULL)
		return NULL;

	queueNode->dataNode = malloc(sizeof(DataNode) * 1);
	if(queueNode->dataNode == NULL)
		return NULL;

	return queueNode;
}

// Interaction Methods
Queue *enqueue(Queue *queue, QueueNode *queueNode)
{
	if(queue == NULL)
		return NULL;

	if(queue->head == NULL)
		queue->head = queue->tail = queueNode;
	else
	{
		queue->tail->next = queueNode;
		queue->tail = queueNode;
	}
	return queue;
}

Queue *simple_enqueue(Queue *queue, char c, int i)
{
	if(queue == NULL)
		return NULL;

	QueueNode *queueNode = create_queue_node();
	queueNode->dataNode->char_data = c;
	queueNode->dataNode->int_data = i;

	return enqueue(queue, queueNode);
}

QueueNode *dequeue(Queue *queue)
{
	if(queue == NULL || queue->head == NULL)
		return NULL;

	QueueNode *queueNode = queue->head;
	queue->head = queueNode->next;

	return queueNode;
}

QueueNode *peek(Queue *queue)
{
	return (queue == NULL) ? NULL : queue->head;
}

// Displaying the Queue
void print_queue(Queue *queue)
{
	print_queue_helper(queue->head);
	printf("\n");
}

void print_queue_helper(QueueNode *queueNode)
{
	if(queueNode == NULL)
	{
		printf("[END]\n");
		return;
	}

	print_queue_node(queueNode);
	print_queue_helper(queueNode->next);
}

void print_queue_node(QueueNode *queueNode)
{
	if(queueNode == NULL)
	{
		printf("NULL\n");
		return;
	}

	char char_data = queueNode->dataNode->char_data;
	int int_data = queueNode->dataNode->int_data;

	printf("[%c : %d]\n", char_data, int_data);
}

int isEmpty(Queue *queue)
{
	return (queue == NULL || queue->head == NULL) ? 1 : 0;
}

#endif