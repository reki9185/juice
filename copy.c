#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char**argv){
	int fd1;
	int fd2;
	char file1[1024];
	char file2[1024];
	char*buf;
	unsigned int filesize;
	int readsize;
	strcpy(file1,argv[1]);
	strcpy(file2,argv[2]);
	fd1=open(file1,O_RDONLY);
	fd2=open(file2,O_WRONLY);
	if(fd1<0){
		printf("error\n");
	}
	if(fd2<0){
		open(file2,O_CREAT);
		fd2=open(file2,O_WRONLY);
	}
	filesize=lseek(fd1,0,SEEK_END);
	buf=(char*)malloc(filesize+1);
	lseek(fd1,0,SEEK_SET);
	readsize=read(fd1,buf,filesize);
	buf[filesize]='\0';
	write(fd2,buf,filesize);
	return 0;
}
