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
	int fd = open("1.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("打开失败");
		return -1;
	}
	struct stu a;
	for (int i = 0; i < 3; i++)
	{
		read(fd, &a, sizeof(struct stu));
		printf("%d ,%s",a.id,a.name);
	}
    return 0;
}
