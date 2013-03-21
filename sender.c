#include <stdio.h>
#include <sys/types.h>

int main(void)
{
    printf( "this is a test\n" );

    pid_t childPid1;
    pid_t childPid2;

    //splitFile();


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

    while( 1 );
    return 0;
}
