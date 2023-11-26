// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */

	// sursa aici https://stackoverflow.com/questions/8475609/implementing-your-own-malloc-free-with-mmap-and-munmap
	// Domnul profesor Deaconescu a spus ca putem folosi surse externe
	int *ptr;
    int len = size + sizeof(size);

    ptr = mmap(0, len, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);

    *ptr = len;
    return (void*)(&ptr[1]);
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *ptr = malloc(nmemb * size);
	memset(ptr, 0, nmemb * size);

	return ptr;
}

void free(void *ptr)
{
	// sursa aici https://stackoverflow.com/questions/8475609/implementing-your-own-malloc-free-with-mmap-and-munmap
	/* TODO: Implement free(). */
	int *pointer = (int*)ptr;
    int len;

    pointer--;
    len = *pointer;

    munmap((void*)pointer, len);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	void *new_ptr = malloc(size);
	memcpy(new_ptr, ptr, size);
	free(ptr);

	return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	void *new_ptr = malloc(nmemb * size);
	memcpy(new_ptr, ptr, nmemb * size);
	free(ptr);

	return new_ptr;
}
