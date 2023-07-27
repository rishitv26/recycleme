#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <iostream>
#include "Eigen/Dense"
#include "asio/include/asio.hpp"
#define ASIO_STANDALONE

using std::string;
using namespace Eigen;

#define ERROR(msg) { std::cout << msg << '\n'; exit(1); }

// Create class Channel, to privately talk to an IP address.
class Channel {
private:
	VectorXd key;
	string& password;
	unsigned int port;

	char* buffer;
	unsigned long buffer_max;
	char end;

public:
	Channel(
		VectorXd, // key for communication
		string&, // password
		unsigned int, // communication port
		unsigned long, // max buffer size (must be length of key matrix)
		char = (char)3 // marks end of communication
	);
	~Channel();
	void listen();
};

#endif // COMMON_H