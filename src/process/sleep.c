#include <internal/syscall.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;

    int ret = nanosleep(&req, &rem);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return (unsigned int)ret;
}
