#include "philosophers.h"

//	do not use after fork()! it would only close one procoess
void	yerror(char *msg)
{
	printf("%s[Error]\n    %s%s\n", BHRED, msg, END);
	exit(1);
}

//	uses memset
void	*ycalloc(const size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		yerror("failed to allocate memory");
	return (memset(ptr, 0, size));
}