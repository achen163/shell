#include <iostream>
#include "../header/executioner.h"

int Executioner::execute(char* args[]) {
	pid_t pid = fork();
	if(pid < 0) {
		perror("forking failed");
	}
	if(pid == 0) {
		cout << "running child process" << pid << endl;
		if(execvp(args[0], args) == -1) {
			perror("execution error");
			return 1;  // invalid command
		}
	} 
	if(pid > 0) {
		if(waitpid(-1, NULL, 0) == -1) 
			perror("wait for child to finish");
		cout << "running parent process: " << pid << endl;
	}
	return 0; // execvp is sucessful
}
