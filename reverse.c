#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char**argv){
	int fd;
	char filename[1024];
	char*buf;
	char*output;
	int readsize;
	unsigned int filesize;
	strcpy(filename,argv[1]);
	fd=open(filename,O_RDWR);
	filesize=lseek(fd,0,SEEK_END);
	buf=(char*)malloc(filesize+1);
	output=(char*)malloc(filesize+1);
	lseek(fd,0,SEEK_SET);
	read(fd,buf,filesize);
	buf[filesize]='\0';
	for(int i=0;i<filesize;i++){
		output[i]=buf[filesize-1-i];
	}
	output[filesize]='\0';
	lseek(fd,0,SEEK_SET);
	write(fd,output,filesize);
	return 0;
}
