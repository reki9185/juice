#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc,char**argv){
	int fd;
	char filename[1024];
	char*buf;
	int readsize;
	unsigned int filesize;
	strcpy(filename,argv[1]);
	fd=open(filename,O_RDWR);
	filesize=lseek(fd,0,SEEK_END);
	buf=(char*)malloc(filesize+1);
	lseek(fd,0,SEEK_SET);
	readsize=read(fd,buf,filesize);
	for(int i=0;i<filesize;i++){
		if(isupper(buf[i])){
			buf[i]=tolower(buf[i]);
		}
	}
	buf[filesize]='\0';
	lseek(fd,0,SEEK_SET);
	write(fd,buf,filesize);
	return 0;
}
