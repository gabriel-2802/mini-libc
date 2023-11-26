#include <time.h>
#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>


int nanosleep(const struct timespec *req, struct timespec *rem) {
    // https://man7.org/linux/man-pages/man2/nanosleep.2.html antetul functiei este de aici
    int ret = syscall(__NR_nanosleep, req, rem);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

