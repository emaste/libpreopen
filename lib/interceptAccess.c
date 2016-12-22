/*
 * interceptAccess.c
 *
 *  Created on: Oct 15, 2016
 *      Author: ujay
 */
#include<dlfcn.h>
#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<dirent.h>
#include<fcntl.h>
#include"cwrapHeader.h"

int (*real_faccessat)(int fd1,const char* pathname1,int mode,int flag);
int access(const char *pathname,int mode){
	real_faccessat=dlsym(RTLD_NEXT,"faccessat");
	return real_faccessat(AT_FDCWD,pathname,mode, AT_EACCESS);

}


