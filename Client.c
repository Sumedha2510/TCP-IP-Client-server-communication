#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main()
{
        int network_socket;
        network_socket = socket(AF_INET, SOCK_STREAM,0);
        struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(9002);
        int connect_status = connect(network_socket,(struct sockaddr*) &server_address, sizeof(server_address));
        if(connect_status == -1)
        {
                printf("Connection failed");
        }
        char server_response[256];
        recv(network_socket, &server_response, sizeof(server_response),0);
        printf("Server sent the data %s\n",server_response);
        return 0;
}
