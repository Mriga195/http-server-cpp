#include <iostream>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

int main()
{
    int fd = open("test.txt", O_RDONLY);

    if (fd == -1)
    {
        cout << "no file found" << endl;
        return 1;
    }
    char buf[100];
    int n = read(fd, buf, 100);

    while (n > 0)
    {
        write(1, buf, n);
        n = read(fd, buf, 100);
    }

    close(fd);
}