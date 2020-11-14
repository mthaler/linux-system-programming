#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd;
    
    fd = creat("/tmp/test", 0644);
    if (fd == -1)
            perror("creat");
}
