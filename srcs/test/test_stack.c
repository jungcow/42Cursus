#include <stdio.h>
#include "create.h"

int test_stack(t_pair *pair)
{
	printf("size: %d\n", pair->a.size);
	while (pair->a.head)
	{
		printf("%d\n", pair->a.head->value);
		pair->a.head = pair->a.head->next;
	}
	printf("_\n");
	printf("a\n");
	return (0);
}
