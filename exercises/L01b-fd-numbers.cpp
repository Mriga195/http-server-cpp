#include <iostream>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

int main()
{
    int fd1 = open("test.txt", O_RDONLY);
    int fd2 = open("test.txt", O_RDONLY);
    int fd3 = open("test.txt", O_RDONLY);

    cout << fd1 << " " << fd2 << " " << fd3 << endl;
    close(fd2);
    int fd4 = open("test.txt", O_RDONLY);
    cout << fd1 << " " << fd2 << " " << fd3 << " " << fd4 << endl;
}