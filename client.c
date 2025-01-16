#include "chatAppfunc.c"

int main()
{

    char *ip = "127.0.0.1";

    struct sockaddr_in address;

    int sockFD = ip4_generate_SockFD_sockAddrin(&address, "127.0.0.1", 8000);

    if (sockFD < 0)
    {
        printf("error creating Socket\n");
        return -1;
    }

    int checkConnect = connect(sockFD, (struct sockaddr *)&address, sizeof(address)); // connect to server

    if (checkConnect == 0)
    {
        printf("connected\n");
    }
    else
    {
        printf("Not Connected\n");
        return -1;
    }

    Send_Data(sockFD); //Sending data to server
close(sockFD);
    return 0;
}