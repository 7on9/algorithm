#include <stdio.h>
#include <unistd.h>

void do_child( int data_pipes[] )
{
    int c;
    int rc;
    close( data_pipes[1] );
    while ( ( rc = read( data_pipes[0], &c, 1 ) ) > 0 )
        {
            putchar( c );
            }
    exit( 0 );
}

void do_parent( int data_pipes[] )
{
    int c;
    int rc;
    close( data_pipes[0] );
    /*Nhận dữ liệu do người dùng nhập vào và ghi vào đường ống */
    while ( ( c = getchar() ) > 0 )
        {
            ​/*Ghi dữ liệu vào đường ống*/
            ​rc = write( data_pipes[1], &c, 1 );
            ​if ( rc == -1 )
                ​{
                    ​perror( "Parent: pipe write error" );
                    ​close( data_pipes[1] );
                    ​exit( 1 );
                    ​}
            ​}
    ​/*Đóng đường ống phía đầu ghi để thông báo cho phía cuối đường ống dữ liệu đã hết*/
    ​close(data_pipe[1]);
    ​exit(0);
}

/*Chương trình chính*/
int main()
{
    ​int data_pipes[2];​/*Mảng chứa số mô tả đọc ghi của đường ống*/
    ​int pid;​/*pid của tiến trình con*/
    ​int rc;​/*Lưu mã lỗi trả về*/
    ​rc = pipe( data_pipes ); ​​/*Tạo đường ống*/
    ​if ( rc == -1 )
        ​{
            ​    perror( "Error: pipe not created" );
            ​exit( 1 );
            ​}
    ​/*Tạo tiến trình con*/
    ​pid = fork();
    ​switch ( pid )
    ​{
            ​case -1: ​/*Không tạo được tiến trình con*/
            ​perror( "Child process not create" );
            ​exit( 1 );
            ​case 0:​/*Tiến trình con*/
            ​do_child( data_pipes );
            ​default:​/*Tiến trình cha*/
            ​do_parent( data_pipes );
        ​}
    ​return 0;
}



