#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    char message[512];

    // socket creation
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
   /*
    DO the required connection
   */

    // closing the socket connection
    close(server_socket);

    return 0;
}
