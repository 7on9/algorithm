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
    char str[]="12@5@+";
    
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
    int result;
    read(sever_id, &result, sizeof(result));
    printf("Result : %d\n", result);
    close(sever_id);
    return 0;
}
