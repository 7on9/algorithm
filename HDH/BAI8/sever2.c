#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    int server_id, client_id;
    int server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    /* 2. Thực hiện khởi tạo socket mới cho trình chủ */
    server_id = socket( AF_INET, SOCK_STREAM, 0 );

    /* 3. Đặt tên và gán địa chỉ kết nối cho socket theo giao thức Internet */
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr( "127.0.0.1" );
    server_address.sin_port = htons( 9734 );
    server_len = sizeof( server_address );
    
    bind( server_id, (struct sockaddr *)&server_address, server_len );
    //Open Queue
    listen( server_id, 5 );

    while ( 1 ) 
    {
        char ch;

        //Wait and accept connection
        printf( "server waiting...\n" );
        client_id = accept( server_id, (struct sockaddr*)&client_address, &client_len );
        
        //read data from client 
        read( client_id, &ch, 1 );
        ch++;
        sleep(5);
        //send to client 
        write( client_id, &ch,1 );

        //close connection
        close( client_id );
    }
    return 0;
}