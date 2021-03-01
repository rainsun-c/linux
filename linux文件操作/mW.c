//用虚拟内存映射的方式 往文件中写入数据
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>//close
#include <stdlib.h>//exit
#include <sys/mman.h>
#include <string.h>
struct student{
	int id;
	char name[20];
	int age;
	double score;
};
int main(){
	//1 创建文件
	int fd = open("stu.txt",O_CREAT | O_RDWR);
	if(-1 == fd) printf("打开文件失败:%m\n"),exit(-1);
	printf("打开文件成功!\n");

	//修改文件大小
	ftruncate(fd,3*sizeof(struct student));


	//3 映射虚拟内存
	struct student* pp = mmap(NULL,3*sizeof(struct student),
		PROT_WRITE|PROT_READ,
		MAP_SHARED,fd,0);
	if((void*)-1 == pp)
		printf("映射虚拟内存失败:%m"),close(fd),exit(-1);
	printf("映射虚拟内存成功!\n");


	//4 使用内存
	struct student* ppp = pp;
	ppp->id = 1;
	strcpy(ppp->name,"张三");
	ppp->age = 33;
	ppp->score = 1.3;
	ppp++;

	ppp->id = 2;
	strcpy(ppp->name,"李四");
	ppp->age = 44;
	ppp->score = 4.3;

	ppp++;
	ppp->id = 3;
	strcpy(ppp->name,"王五");
	ppp->age = 55;
	ppp->score = 51.3;

	printf("写入数据完毕");
	//5 接触虚拟内存映射
	int ret = munmap(pp,3*sizeof(struct student));
	if(ret)
		printf("munmmap失败:%m"),exit(-1);
	printf("munmap成功!\n");

	//7 关闭文件
	close(fd);

	return 0;
}