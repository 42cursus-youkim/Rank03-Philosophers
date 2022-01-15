#include "philosophers.h"

//	do not use after fork()! it only closes one procoess
void	yerror(char *where, char *msg)
{
	printf("%s[Error! @ %s]\n    %s%s\n", BHRED, where, msg, END);
	exit(1);
}

//	uses memset
void	*ycalloc(const size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		yerror("ycalloc", "failed to allocate memory");
	return (memset(ptr, 0, size));
}