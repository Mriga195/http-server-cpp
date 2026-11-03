#include <iostream>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

int main()
{
    int counter = 0;
    int fd;

    do
    {
        fd = open("test.txt", O_RDONLY);
        counter++;
    } while (fd > 0);

    cout << counter;
}