#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
int main()
{
    int sever_id;
    int sever_len;
    struct sockaddr_un sever_address;
    char str[]="yasuo";
    
    //create socket 
    sever_id = socket(AF_UNIX, SOCK_STREAM, 0);
    
    //set attr
    sever_address.sun_family = AF_UNIX;
    strcpy(sever_address.sun_path, "SK");

    //set length
    sever_len = sizeof(sever_address);
    
    //connect 
    connect(sever_id, (struct sockaddr*) &sever_address, sever_len);
    write(sever_id, &str, strlen(str));
    read(sever_id, &str, strlen(str));
    printf("Ky tu nhan duoc tu sever : %s\n", str);
    close(sever_id);
    return 0;
}