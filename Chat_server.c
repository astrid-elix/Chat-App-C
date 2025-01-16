
#include "chatAppfunc.c"

int main()
{

    char *ip = "127.0.0.1";
    struct sockaddr_in address;
    int sockFD = ip4_generate_SockFD_sockAddrin(&address, ip, 8000);

    int bindresult = bind(sockFD, (struct sockaddr *)&address, sizeof(address)); // bind the port

    if (bindresult == 0)
    {
        printf("Bind Successfull\n");
    }
    else
    {
        printf("Bind not successfull\n");
        return -1;
    }

    int Listenresult = listen(sockFD, 10);  //listning in port and queue is 10 
    int size = sizeof(address);
    int Client_Socket;

    if (Listenresult == 0)
    {
     Client_Socket = accept(sockFD, (struct sockaddr *)&address, &size); // accepting the client and getting client socket
    }

    if (Client_Socket<0)
    {
        printf("Error Connecting client Socket\n");
    }
    
 Recive_data(Client_Socket); // reciving data from client

  
    close(sockFD);
    return 0;
}