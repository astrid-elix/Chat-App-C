#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int ip4_generate_SockFD_sockAddrin(struct sockaddr_in *address, char *ip, int port)
{
    int sockFD = socket(AF_INET, SOCK_STREAM, 0);
    address->sin_family = AF_INET;
    address->sin_port = htons(port);
    inet_pton(AF_INET, ip, &address->sin_addr);
    return sockFD;
}

void Send_Data(int sockFD)
{
    char buff[1024];

    while (1)
    {
        buff[0] = '\0';
        fgets(buff, 1023, stdin);

        send(sockFD, buff, strlen(buff), 0);

        if (!strcmp(buff, "/exit\n"))
        {
            break;
        }
    }
}


void Recive_data(int Client_Socket)
{
   char buff[1024];
  while (1)
    {
        memset(buff, 0, 1024);
        recv(Client_Socket, buff, 1024, 0);

        if (!strcmp(buff, "/exit\n"))
        {
            break;
        }

        printf("%s", buff);
    }
}
