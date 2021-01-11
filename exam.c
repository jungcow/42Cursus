#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

typedef struct	s_backup
{
	char		*str;
	int			sum;
	char		*tmp;
	char		buffer[BUFFER_SIZE];
}				t_backup;

void	test(void)
{
	static t_backup b;

	printf("%d\n", b.sum);
}

void	test1(void)
{
	t_backup a;

	printf("%d\n", a.sum);
}


int main(void)
{
	test();
	test1();
	return (0);
}
