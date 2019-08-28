#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5
int node_count = 0;

typedef struct stack_node
{
	int data;
	stack_node* next;
};

// 
typedef struct stack
{
	stack_node* top;
};

stack* init_stack(stack* st)
{
	st->top = NULL;
	
	return st;
}

bool is_stack_empty(stack* st)
{
	if (st->top == NULL)
	{
		return true;
	}

	return false;
}

bool is_stack_full(stack* st)
{
	if (node_count == MAX_SIZE)
	{
		printf("push failed, stack is full.\n");
		return true;
	}
	return false;
}

stack* push_stack(stack* st, int value)
{
	//if (is_stack_empty(st))	// ���ù�stack�Ƿ�ǿ�
	//{
	//	st->top = new_node;
	//	
	//	return st;
	//}
	stack_node* new_node = (stack_node*)malloc(1 * sizeof(stack_node));
	new_node->data = value;
	new_node->next = NULL;

	if (!is_stack_full(st))
	{
		new_node->next = st->top;
		st->top = new_node;
		node_count++;			// �ڵ���
	}
	else
	{
		printf("stack is full.\n");
	}

	return st;
}

void pop_stack(stack* st)
{
	stack_node* ptr_current = st->top;
	if (!is_stack_empty(st))
	{			
		printf("pop value is :%d\n", st->top->data);
		st->top = st->top->next;
		free(ptr_current);
		ptr_current = NULL;
		node_count--;	
	}
	else
	{
		printf("stack is empty.\n");
	}
}

// ��ȡջ��Ԫ��ֵ
int get_stack_top_value(stack* st)
{
	return st->top->data;
}

// ��ȡջԪ�ظ���
int get_count(stack* st)
{
	return node_count;
}

void printf_stack(stack* st)
{
	stack_node* ptr_current = st->top;
	while (ptr_current != NULL)
	{
		printf("%d\t", ptr_current->data);
		ptr_current = ptr_current->next;
	}
	printf("\n");
}

int main()
{
	stack* st = (stack*)malloc(1*sizeof(stack));
	init_stack(st);
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		push_stack(st, i);
	}
	printf("��ʼջԪ�أ�\n");
	printf_stack(st);

	pop_stack(st);
	push_stack(st, 55);
	pop_stack(st);

	printf("ջ������\n");
	printf_stack(st);

	int count = get_count(st);
	printf("count = %d\n", count);

	int top_value = get_stack_top_value(st);
	printf("top_value = %d\n", top_value);

	free(st);	// ����ǵ��ͷ�;
	st = NULL;

	getchar();
	return 0;
}
