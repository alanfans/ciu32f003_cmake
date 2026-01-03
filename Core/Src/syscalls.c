/*
 * syscalls.c
 * System call stubs for embedded environment
 * Required to eliminate newlib-nano linker warnings
 */

#include <sys/stat.h>
#include <sys/unistd.h>

// Forward declaration for _sbrk
extern char _end;

// Heap start pointer
char *heap_end = 0;

int _write(int file, char *ptr, int len) {
    (void)file; (void)ptr;
    return len;
}

int _read(int file, char *ptr, int len) {
    (void)file; (void)ptr; (void)len;
    return 0;
}

int _lseek(int file, int ptr, int dir) {
    (void)file; (void)ptr; (void)dir;
    return 0;
}

int _close(int file) {
    (void)file;
    return -1;
}

int _fstat(int file, struct stat *st) {
    (void)file;
    st->st_mode = S_IFCHR;
    return 0;
}

int _isatty(int file) {
    (void)file;
    return 1;
}

int _kill(int pid, int sig) {
    (void)pid; (void)sig;
    return -1;
}

int _getpid(void) {
    return 1;
}

// Heap management for malloc()
caddr_t _sbrk(int incr) {
    (void)incr;
    extern char _end;
    static char *heap_top = &_end;
    char *prev_heap_top;

    prev_heap_top = heap_top;
    heap_top += incr;
    return (caddr_t) prev_heap_top;
}
