#include "common.h"

Channel::Channel(VectorXd K, string& pass, unsigned int p, unsigned long charperbuffer, char e)
	:key(K),password(pass),port(p),buffer_max(charperbuffer),end(e)
{
	if (K.size() != charperbuffer) {
		ERROR("Leme explain why I crashed.\nThe size of K must be "
			  "equal to the char per buffer, so that I can work properly"
			  ".\n\nThanks for understanding.");
	}
}

Channel::~Channel(){}

void Channel::listen()
{

}


