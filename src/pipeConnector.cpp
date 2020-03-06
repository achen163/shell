#include "../header/pipeConnector.h"

string pipeConnector::item() {
	return "|";
}

void pipeConnector::setLeft(Token* token) {
	left = token;
}

void pipeConnector::setRight(Token* token) {
	right = token;	
}

bool pipeConnector::evaluate() {
	

}
int pipeConnector::evaluate2(int inputfile, int outputfile) {
	int fds[2];
	pipe(fds);
	
	left->evaluate(in, fds[1]);
	close(fds[1]);
	
	right->evaluate(fds[0], out);
	close(fds[0]);

	return true;
}
