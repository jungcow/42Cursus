#include <stdio.h>
#include "create.h"
#include "operation.h"

int test_push_a(t_pair *pair)
{
	push_a(&pair->a, &pair->b);
	return (0);
}
