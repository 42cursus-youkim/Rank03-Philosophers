#include "philosophers.h"

void	yerror(const char *msg)
{
	printf("%s[Error]\n\t%s%s\n", HRED, msg, END);
	exit(EXIT_FAILURE);
}
