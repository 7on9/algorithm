#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
int main()
{
    int sever_id, client_id;
    int sever_len, client_len;
    struct sockaddr_un sever_address, client_address;

    //interupt connection 
    unlink("SK");
    sever_id = socket(AF_UNIX, SOCK_STREAM, 0);
    sever_address.sun_family = AF_UNIX;
    strcpy(sever_address.sun_path, "SK");
    sever_len = sizeof(sever_address);
    
    //name socket
    bind(sever_id,(struct sockaddr*) &sever_address,sever_len);

    //listen from client
    listen(sever_id, 10);
    while(1)
    {
        char c;
        printf("Sever waiting ... \n");
        client_id = accept(sever_id, (struct sockaddr*) &client_address, &client_len);
        read(client_id, &c, 1);
        c++;
        write(client_id, &c, 1);

        //close connect
        close(client_id);
    }
    return 0;
}