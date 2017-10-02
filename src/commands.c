#include <string.h>
#include <unistd.h>
//#include <stdio.h>

#include "commands.h"

int do_cd(int argc, char** argv) {
	char* path = (char *)malloc(sizeof(char*) * 128);
	if (!validate_cd_argv(argc, argv))
    return -1;
	strcpy(path, argv[1]);
  // TODO: Fill it!
	if(chdir(path))
		printf("No such file or directory\n");
	free(path);
	return 0;
}

int do_pwd(int argc, char** argv) {
	size_t path_size = 128;
	char* path = (char*)malloc(sizeof(char*) * path_size);

	if (!validate_pwd_argv(argc, argv))
    return -1;
  // TODO: Fill it!
	getcwd(path, path_size);
	printf(">> %s\n", path);
	free(path);
  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  // TODO: Fill it!
	if(argc != 2)
		return 0;

	return 1;
}

int validate_pwd_argv(int argc, char** argv) {
  // TODO: Fill it!
 	if(argc != 1)
		return 0;
	
	return 1;
}
