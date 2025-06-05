#ifndef REGISTER_H
#define REGISTER_H

#include <string>
#include "packet.h"
#include "user.h"
#include "protocol.h"

class Register : public Packet {
private:
	
public:
	Register() : Packet() {};
	Register(User user , Protocol proto) : Packet(user , proto) {};

	void send() override;

};
#endif