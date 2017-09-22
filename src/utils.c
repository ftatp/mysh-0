#include <stdlib.h>
#include <string.h>

#include "utils.h"
#define MAX_INPUT_LENGTH 128

void mysh_parse_command(const char* command,
                        int *argcp, char*** argvp)
{
  // TODO: Fill this!
	int i;
	char* buf = (char*)malloc(sizeof(char) * 8096);
	char* token = (char*)malloc(sizeof(char) * MAX_INPUT_LENGTH);

	//int argc = *argcp;
	//char** argv = *argvp;

	*argcp = 50;
	*argvp = (char**)malloc(sizeof(char*) * (*argcp));
  for(i = 0; i < *argcp; i++){
	  *(*argvp + i) = (char*)malloc(sizeof(char) * MAX_INPUT_LENGTH);
		memset(*(*argvp + i), 0, MAX_INPUT_LENGTH);
	}

	printf("command: %s\n", command);

	strcpy(buf, command);
	buf[strlen(buf) - 1] = 0;

	i = 0;
	token = strtok(buf, " ");
	while(token != NULL){
		strcpy(*(*argvp + (i++)), token);
		token = strtok(NULL, " ");
		printf("%s\n", *(*argvp + (i - 1)));
	}

	free(buf);
	free(token);
}
