#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
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
        char str[1000];
        printf("Sever waiting ... \n");
        client_id = accept(sever_id, (struct sockaddr*) &client_address, &client_len);
        read(client_id, &str, 100);
        for(int i = 0;i < strlen(str);i++)
            str[i] -= 32;
        write(client_id, &str, strlen(str));

        //close connect
        close(client_id);
    }
    return 0;
}