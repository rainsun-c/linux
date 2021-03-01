//用虚拟内存映射的方式 从文件中读取数据
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>//close
#include <stdlib.h>//exit

#include <sys/mman.h>
struct student{
	int id;
	char name[20];
	int age;
	double score;
};

int main(){
	int fd = open("stu.txt",O_RDONLY);

	struct student* p = mmap(NULL,3*sizeof(struct student),PROT_READ,
		MAP_SHARED,fd,0);

	struct student* pp = p;

	for(int i=0;i<3;i++){
		printf("%d:%s:%d:%g\n",pp->id,pp->name,pp->age,pp->score);
		pp++;
	}
	munmap(p,3*sizeof(struct student));
	close(fd);

	return 0;
}