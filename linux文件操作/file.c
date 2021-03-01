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
		perror("打开失败:");
		//return -1;
		fd = open("1.txt", O_CREAT | O_WRONLY, 0666);
		if (fd == -1)
		{
			perror("打开失败:");
			return -1;
		}

		close(fd);
	}
	fd = open("1.txt", O_RDONLY);
	printf("打开成功\n");

    struct stu s[3] = { {1,"皇子"},{2,"奇热"},{3,"达瓦"} };
	for (int i = 0; i < 3; i++)
	{
		write(fd,&s[i],sizeof(struct stu));
	}


	close(fd);
	return 0;
}