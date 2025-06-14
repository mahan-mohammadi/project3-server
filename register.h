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
	virtual ~Register() {}
	Register(User user , Protocol proto) : Packet(user , proto) {};
	Register(string);

};
#endif