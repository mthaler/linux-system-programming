#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main() {
    int fd;
    fd = open("/tmp/test.txt", O_RDONLY);
    if (fd == -1)
        perror ("open");
    
    ssize_t ret;
    int len = 1024;
    unsigned char buffer[1024];
    unsigned char *buf = buffer;
    while(len != 0 && (ret = read(fd, buf, len)) != 0) {
        if (ret == -1) {
            if (errno == EINTR)
                continue;
            perror("read");
            break;
        }
        
        len -= ret;
        buf += ret;
    }
}
