#ifndef _STACK_H
#define _STACK_H

// This can hold whatever data needed for a single DataNode, you 
// typedef struct node
// {
// 	char data;
// } DataNode;

typedef struct stackNode
{
	DataNode *dataNode;
	struct stackNode *next;
} stackNode;

typedef struct Stack 
{
	stackNode *top;
} Stack;

// Creates the and innitializes the Stack
Stack *create_stack()
{
	Stack *newStack = malloc(sizeof(Stack) * 1);
	newStack->top = NULL;
	return newStack;
}

// Creates a node to contain data
DataNode *create_node()
{
	DataNode *newNode = malloc( sizeof(DataNode) * 1);
	newNode->data = ' ';
	return newNode;
}

Stack *push_node(Stack *stack, DataNode *node)
{
	if(stack == NULL)
		return NULL;
	
	stackNode *newTop = malloc( sizeof(stackNode) * 1);
	newTop->dataNode = node;
	newTop->next = stack->top;
	stack->top = newTop;

	return stack;
}

Stack *push_char(Stack *stack, char c)
{
	if(stack == NULL)
		return NULL;
	
	stackNode *newTop = malloc( sizeof(stackNode) * 1);
	newTop->dataNode = create_node();
	newTop->dataNode->data = c;
	newTop->next = stack->top;
	stack->top = newTop;

	return stack;
}

stackNode *pop(Stack *stack)
{
	if(stack == NULL || stack->top == NULL)
		return NULL;

	stackNode *sNode = stack->top;
	stack->top = stack->top->next;
	return sNode;
}

Stack *clear_stack(Stack *stack)
{
	stackNode *top;
	while( (top = pop(stack) ) != NULL )
	{
		free(top->dataNode);
		free(top);
	}

	if(stack != NULL)
		free(stack);

	return NULL;
}

void recPrint(stackNode *sNode)
{
	if(sNode == NULL)
	{
		printf("[END]\n");
		return;
	}

	printf("[%c]->", sNode->dataNode->data);
	recPrint(sNode->next);
	return;
}

void printStack(Stack *stack)
{
	if(stack == NULL)
		return;
	recPrint(stack->top)
}

#endif
