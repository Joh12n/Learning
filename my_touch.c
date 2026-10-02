#include<stdio.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include<unistd.h>
#include<string.h>
#include<time.h>
#include<sys/stat.h>
#include<errno.h>
#include<stdlib.h>
       /*int fstatat(int dirfd, const char *restrict path,
                struct stat *restrict statbuf, int flags)*/

//Update the access and modification times of each FILE to the current time.
int main(int argc,char *argv[])
{
	if(argc!=2){
		printf("Expected arguments number is 2!\n");
		return -1;
	}
	else if(argc > 2){
		printf("too many arguments!\n");
		return -1;
	}
	char *path=strcat(getenv("PWD"),"/");
	path=strcat(path,argv[1]);
	struct stat sb;
	int ret=fstatat(AT_FDCWD, path,&sb, 0);
	if(ret!=0)
	{
		//the file isn't exist,should create first
		printf("create the file first!\n");
		int fd=open(path,O_CREAT,0666);
		printf("the fd is :%d\n",fd);
		close(fd);

	}
	ret=fstatat(AT_FDCWD,path,&sb,0);
	if(ret!=0) perror("create failed");
	printf("ino_t:%ld\n",sb.st_ino);
	time_t atim=sb.st_atim.tv_sec;
	time_t mtim=sb.st_mtim.tv_sec;
	struct tm *at=localtime(&atim);
	struct tm *mt=localtime(&mtim);
	char outstr1[200];
	char outstr2[200];
	strftime(outstr1,sizeof(outstr1),"%Y-%m-%d %H:%M:%S",at);
	strftime(outstr2,sizeof(outstr2),"%Y-%m-%d %H:%M:%S",mt);
	printf("the snapshot's mtim is \"%s\"\n",outstr1);
	printf("the snapshot's atim is \"%s\"\n",outstr2);
	return 0;
}
