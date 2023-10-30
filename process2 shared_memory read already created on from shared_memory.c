#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{  
    int shmid;
    char buff[1024];
    void *shared_memory;
    int i;
    shmid=shmget((key_t)2345,1024,0666);
    printf("key of the shared memory %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("process attached to the shared memory\n");
    printf("data reading from shared memoery \n %s\n",(char *)shared_memory);
    
    return 0;
}
