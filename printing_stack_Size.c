#include<stdio.h>
#include<pthread.h>
pthread_t t1,t2;

void *fun(void *arg)
{
    printf("inside the function\n");
}
int main()
{
    size_t stksize;
    int n;
    pthread_attr_t attr;
    
    printf("starting the program enter n value\n");
    scanf("%d",&n);
    if(pthread_attr_init(&attr) !=0 )
    {
        perror("pthread_attr_init is failed");
        return 1;
        
    }
    
    if(pthread_attr_getstacksize(&attr,&stksize) != 0)
    {
        perror(" pthread_attr_getstacksize failed");
        return 1;
    }
    
    printf("stack size %zu\n",stksize);
    
    pthread_create(&t1,&attr,fun,NULL);
    pthread_create(&t2,&attr,fun,NULL);
    pthread_join(t1,0);
    pthread_join(t2,0);
    
    pthread_attr_destroy(&attr);
    
    return 0;
}
