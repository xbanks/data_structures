#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


int main(int argc, char const *argv[])
{
	Queue *queue = create_queue(queue);
	if (queue == NULL)
	{
		printf("The queue was not able to be created\n");
		return 1;
	}

	queue = simple_enqueue(queue, 'X', 25);
	queue = simple_enqueue(queue, 'R', 938481);
	print_queue(queue);
	clear_node(dequeue(queue));
	print_queue(queue);

	
	queue = clear_queue(queue);
	return 0;
}