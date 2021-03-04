#include <stdio.h>
#include <unistd.h>

int main()
{
    
    
    int n=0;
    printf("调用父进程:%d\n",getpid());
    int ret =fork();
    printf("调用进程:%d\n",getpid());
    
    if(ret)
    {
        while(1)
        {
            printf("调用父进程:%d  n为：%d\n",getpid(),n);
            sleep(1);
            n++;
        }
           
    }
    else
    {
         while(1)
        {
            printf("调用zi进程:%d  n为：%d\n",getpid(),n);
            sleep(1);
            n++;
        }
    }
     
    return 0;
    
}