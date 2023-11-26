// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	int i = 0;
	while (1) {
		destination[i] = source[i];
		if (source[i] == '\0')
			break;
		i++;
	}

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	size_t i = 0;
	while (i < len) {
		destination[i] = source[i];
		i++;
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int dest_len = strlen(destination);
	int src_len = strlen(source);
	int i = 0;

	while (i < src_len) {
		destination[dest_len + i] = source[i];
		i++;
	}

	destination[dest_len + i] = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	int dest_len = strlen(destination);
	int src_len = strlen(source);
	size_t i = 0;

	while (i < (size_t)src_len && i < (size_t)len) {
		destination[dest_len + i] = source[i];
		i++;
	}

	destination[dest_len + i] = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	if (len1 < len2) {
		return -1;
	} else if (len1 > len2) {
		return 1;
	} else {
		// len1 == len2
		int i = 0;
		while (i < len1) {
			if (str1[i] < str2[i])
				return -1;
			else if (str1[i] > str2[i])
				return 1;
			i++;
		}
	}
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	size_t i = 0;
	while (i < len) {
		if (str1[i] < str2[i])
			return -1;
		else if (str1[i] > str2[i])
			return 1;
		i++;
	}

	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	int len = strlen(str);
	int i = 0;
	while (i < len) {
		if (str[i] == c)
			return (char *)str + i;
		i++;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	int len = strlen(str);
	int i = len - 1;
	while (i >= 0) {
		if (str[i] == c)
			return (char *)str + i;
		i--;
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	int needle_len = strlen(needle);
	int haystack_len = strlen(haystack);
	int i = 0;

	while (i < haystack_len) {
		if (!strncmp(haystack + i, needle, needle_len))
			return (char *)haystack + i;
		i++;
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	int needle_len = strlen(needle);
	int i = strlen(haystack) - needle_len;

	while (i > 0) {
		if (!strncmp(haystack + i, needle, needle_len))
			return (char *)haystack + i;
		i--;
	}

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *dest = (char *)destination;
	char *src = (char *)source;

	for (size_t i = 0; i < num; i++)
		dest[i] = src[i];

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dest = (char *)destination;
	char *src = (char *)source;

	for (size_t i = 0; i < num; i++)
		dest[i] = src[i];

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	char *p1 = (char *)ptr1;
	char *p2 = (char *)ptr2;

	for (size_t i = 0; i < num; i++) {
		if (p1[i] < p2[i])
			return -1;
		else if (p1[i] > p2[i])
			return 1;
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *src = (char *)source;
	for (size_t i = 0; i < num; i++)
		src[i] = (char)value;
	return source;
}
