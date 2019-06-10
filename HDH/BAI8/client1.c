#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
int main()
{
    int sever_id;
    int sever_len;
    struct sockaddr_un sever_address;
    char c = 'F';
    
    //create socket 
    sever_id = socket(AF_UNIX, SOCK_STREAM, 0);
    
    //set attr
    sever_address.sun_family = AF_UNIX;
    strcpy(sever_address.sun_path, "SK");

    //set length
    sever_len = sizeof(sever_address);
    
    //connect 
    connect(sever_id, (struct sockaddr*) &sever_address, sever_len);
    write(sever_id, &c, 1);
    read(sever_id, &c, 1);
    printf("Ky tu nhan duoc tu sever : %c\n", c);
    close(sever_id);
    return 0;
}