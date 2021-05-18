#include <stdio.h>
#include "create.h"
#include "operation.h"

int test_push(t_pair *pair)
{
	push_b(&pair->a, &pair->b);
	return (0);
}
