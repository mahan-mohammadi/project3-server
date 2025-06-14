#ifndef PACKET_H
#define PACKET_H

#include <string>
#include "user.h"
#include "protocol.h"

class Packet {
protected:
	User sender;
	Protocol protocol;

public:
	Packet();
	Packet(User, Protocol);

	void setSender(User);
	User getSender();
	void setProtocol(Protocol);
	Protocol getProtocol();
	//virtual void send();
};

#endif