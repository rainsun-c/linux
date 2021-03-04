#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>

int main()
{
    //设置权限 umask
    
    umask(0);
    //2、创建进程
    
    int ret = fork();
    if(ret<0)
    {
        printf("创建失败\n");
        return -1;
    }
    if(ret>0) printf("父进程结束:%m\n"),exit(0);//3. 让父进程结束
        
    if(ret==0)
    {
        printf("pid:%d\n",getpid());
        //创建新对话
        setsid();
        //5、防止子进程成为僵尸进程，忽略SIGCHLD SIGHUP信号。
        signal(SIGCHLD,SIG_IGN);
        signal(SIGHUP,SIG_IGN);
        //6、改变当前工作目录 chdir
        chdir("/");
        //7、重定向文件描述符号 open dup2(fd,0) dup2(fd,1);
        int fd =open("/dev/NULL",O_RDWR);
        dup2(fd,0);
        dup2(fd,1);
        
    }
    while(1)
    {
        printf("sssss");
        sleep(2);
        
    }
    
    
    
    
    return 0;
}
