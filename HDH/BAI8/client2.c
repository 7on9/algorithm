#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
/* dành riêng cho AF_INET */
#include <netinet/in.h>
#include <arpa/inet.h>
 
int main()
{
    int id;
    int len;
    struct sockaddr_in address;
    int result;
    char ch = 'A';

    id = socket( AF_INET, SOCK_STREAM, 0 );

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr( "127.0.0.1" );
    address.sin_port = htons( 9734 );
    len = sizeof( address );

    result = connect( id, (struct sockaddr*)&address, len );
    if ( result == -1 ) 
    {
        perror( "Oops: client1 problem" );
        return 0;
    }

    write( id, &ch, 1 );
    read( id, &ch, 1 );
    printf( "Ky tu tra ve : %c\n", ch );
    close( id );
    return 1;
}