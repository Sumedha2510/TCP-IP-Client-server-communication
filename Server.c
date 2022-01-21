#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main()
{
        char serv_mess[256] = "\nYou have reached the server";
        int server_socket;
        server_socket = socket(AF_INET, SOCK_STREAM,0);
        struct sockaddr_in server_address;
        server_address.sin_port = htons(9002);
        bind(server_socket,(struct sockaddr*) &server_address, sizeof(server_address));
        listen(server_socket,5);
        int client_socket;
        client_socket = accept(server_socket,NULL, NULL);
        send(client_socket,serv_mess, sizeof(serv_mess),0);
        return 0;
}
