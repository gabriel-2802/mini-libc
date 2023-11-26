#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>

int puts(char *str)
{
    int ret = syscall(__NR_write, 1, str, strlen(str));

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    ret = syscall(__NR_write, 1, "\n", 1);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}
