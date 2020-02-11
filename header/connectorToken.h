#ifndef __connectorToken_h__
#define __connectorToken_h__

#include <iostream>
#include "tokenizer.h"

class Connector: public Tokenizer{
	public:
		Connector() : Tokenizer() { }
		virtual const char* stringify(string);
		virtual void evaluate();
		 			
};



#endif
