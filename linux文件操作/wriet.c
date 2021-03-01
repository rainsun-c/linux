#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct stu
{
	int id;
	char name[20];
};



int main()
{
	int fd = open("1.txt", O_RDONLY); //打开文件
	if (fd == -1)
	{
		//perror("打开失败:");
		//return -1;
		fd = open("1.txt", O_CREAT | O_WRONLY, 0666);
		if (fd == -1)
		{
			perror("打开失败:");
			return -1;
		}
	}

    	struct stu s[3] = { {1,"1号"},{2,"2号"},{3,"3号"} };
	for (int i = 0; i < 3; i++)
	{
		write(fd,&s[i],sizeof(struct stu));
	}


	close(fd);
	return 0;
}