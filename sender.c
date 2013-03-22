#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

void splitFile( void )
{
    struct stat buffer;
    int fildes = open( "/Users/vicjang/test50", O_RDWR );
    int status = fstat( fildes, &buffer );
    int filesize = (int)buffer.st_size;

    char spltcmd[100];
    memset( spltcmd, 0, sizeof( spltcmd ) );
    sprintf( spltcmd, "split -b %d /Users/vicjang/test50", filesize / 2 );
    printf( "%s\n", spltcmd );
    system( spltcmd );

    system( "mv xaa /Users/vicjang/xaa" );
    system( "mv xab /Users/vicjang/xab" );
}

int main(void)
{
    printf( "this is a test\n" );

    pid_t childPid1;
    pid_t childPid2;

    splitFile();

    if( ( childPid1 = fork() ) == 0 )
    {
        // child 1
        printf( "first clause %d\n", childPid1 );
        system( "./sendfile 10.0.0.3 90000 1500 38100" );

        //RBUDP_send();
    }
    else
    {
        // parent, fork again
        if( ( childPid2 = fork() ) == 0 )
        {
            // child 2
            printf( "second clause %d\n", childPid2 );
            system( "./sendfile 10.0.0.3 90000 1500 38200" );
        }
        else
        {
            // parent
            printf( "I am the parent\n" );
        }
    }


    printf( "Parallel sending finished.\n" );

    return 0;
}
