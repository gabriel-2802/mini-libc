struct timespec {
    long int  tv_sec;
    long int tv_nsec;
};
// https://man7.org/linux/man-pages/man2/nanosleep.2.html antetul functiei este de aici
// https://www.gnu.org/software/libc/manual/html_node/Time-Types.html#:~:text=time_t%20is%20the%20simplest%20data,time_t%20values%20is%20not%20specified.
// iar structura este de aici
int nanosleep(const struct timespec *req, struct timespec *rem);



