#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

int main()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        perror("bind");
        return 1;
    };

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9000);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (sockaddr *)&addr, sizeof(addr));

    listen(server_fd, 5);

    int client_fd = accept(server_fd, nullptr, nullptr);

    char buf[100];
    int n = read(client_fd, buf, 100);

    while (n > 0)
    {
        write(client_fd, buf, n);
        n = read(client_fd, buf, 100);
    }

    close(client_fd);
    close(server_fd);
}