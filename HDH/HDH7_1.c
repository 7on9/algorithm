#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void batCtrlC( int sig_num )
{
    signal( SIGINT, batCtrlC );
    printf( "Vua nhan Ctrl+C\n" );
}
int main()
{
    int count = 0;
    signal( SIGINT, batCtrlC );
    while ( 1 )
        {
            printf( "Counting … %d\n", count++ );
            sleep( 1 );
        }
}
