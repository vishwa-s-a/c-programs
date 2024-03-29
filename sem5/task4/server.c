#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <stdlib.h>
int main()
{
    char buf[100];
    int k;
    socklen_t len;
    int sock_desc, temp_sock_desc;
    struct sockaddr_in server, client;
    memset(&server, 0, sizeof(server));
    memset(&client, 0, sizeof(client));
    sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_desc == -1)
    {
        printf("Error in socket creation");
        exit(1);
    }
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = 3002;
    k = bind(sock_desc, (struct sockaddr *)&server, sizeof(server));
    // The bind call assigns the address specified in the parameter,server,to the unnanmed socket associated with file
    // descriptor sock_desc.
    if (k == -1)
    {
        printf("Error in binding");
        exit(1);
    }
    k = listen(sock_desc, 20);
    if (k == -1)
    {
        printf("Error in listening");
        exit(1);
    }
    len = sizeof(client);                                                 // VERY IMPORTANT
    temp_sock_desc = accept(sock_desc, (struct sockaddr *)&client, &len); // VERY //IMPORTANT
    if (temp_sock_desc == -1)
    {
        printf("Error in temporary socket creation");
        exit(1);
    }
    while (1)
    {
        k = recv(temp_sock_desc, buf, 100, 0);
        if (k == -1)
        {
            printf("Error in receiving");
            exit(1);
        }
        printf("Message got from client is : %s", buf);
        printf("\nEnter data to be send to client: ");
        fgets(buf, 100, stdin);
        if (strncmp(buf, "end", 3) == 0)
            break;
        k = send(temp_sock_desc, buf, 100, 0);
        if (k == -1)
        {
            printf("Error in sending");
            exit(1);
        }
    }
    close(temp_sock_desc);
    exit(0);
    return 0;
}