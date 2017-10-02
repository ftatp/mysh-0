#include <stdlib.h>
#include <string.h>

#include "utils.h"
#define MAX_INPUT_LENGTH 128

void mysh_parse_command(const char* command,
                        int *p_argc, char*** p_argv)
{
  // TODO: Fill this!
	int i;
	char* buf = (char*)malloc(sizeof(char) * 8096);
	char* token = (char*)malloc(sizeof(char) * MAX_INPUT_LENGTH);

	//int argc = *argcp;
	//char** argv = *argvp;

	*p_argc = 50;
	*p_argv = (char**)malloc(sizeof(char*) * (*p_argc));
	for(i = 0; i < *p_argc; i++){
	  *(*p_argv + i) = (char*)malloc(sizeof(char) * MAX_INPUT_LENGTH);
		memset(*(*p_argv + i), 0, MAX_INPUT_LENGTH);
	}

	//printf("command: %s\n", command);

	strcpy(buf, command);
	buf[strlen(buf) - 1] = 0;

	i = 0;
	*p_argc = 0;
	token = strtok(buf, " ");
	while(token != NULL){
		*p_argc = *p_argc + 1;
		strcpy(*(*p_argv + (i++)), token);
		token = strtok(NULL, " ");
	//	printf("%s\n", *(*p_argv + (i - 1)));
	}

	//printf("argc: %d\n", *p_argc);
	free(buf);
	free(token);
}
