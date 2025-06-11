#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main() {
    int fd = open("/dev/vchar_dev", O_RDWR);
    if (fd < 0) {
        fprintf(stderr, "Failed to open device: %s\n", strerror(errno));
        return 1;
    }

    char buf[256] = {0};
    ssize_t bytes_read = read(fd, buf, sizeof(buf) - 1);
    if (bytes_read < 0) {
        fprintf(stderr, "Failed to read: %s\n", strerror(errno));
    } else {
        buf[bytes_read] = '\0';
        printf("Read: %s\n", buf);
    }

    const char *msg = "Hello from user!";
    ssize_t bytes_written = write(fd, msg, strlen(msg) + 1);
    if (bytes_written < 0) {
        fprintf(stderr, "Failed to write: %s\n", strerror(errno));
    } else {
        printf("Wrote %zd bytes\n", bytes_written);
    }

    close(fd);
    return 0;
}