#include <stdio.h>
#include "create.h"

int test_stack(t_pair *pair)
{
	t_stack	a;
	t_stack	b;

	a = pair->a;
	b = pair->b;
	printf("\n==============\n");
	while (a.head|| b.head)
	{
		if (a.head)
			printf("%d  ", a.head->value);
		else
			printf("    ");
		if (b.head)
			printf("%d", b.head->value);
		printf("\n");
		if (a.head)
			a.head = a.head->next;
		if (b.head)
			b.head = b.head->next;
	}
	printf("_   _\n");
	printf("a   b\n");
	printf("==============\n\n");
	return (0);
}
