#include "packet.h"
#include "protocol.h"

Packet::Packet() {
	sender = User();
	protocol = REG;
}

Packet::Packet(User sender, Protocol type) {
	protocol = type;
	this->sender = User(sender);
}

void Packet::setSender(User sender) {
	this->sender = sender;
}

User Packet::getSender() {
	return sender;
}

void Packet::setProtocol(Protocol type) {
	this->protocol = type;
}

Protocol Packet::getProtocol() {
	return protocol;
}

virtual void Packet::send() {
	// temp
}
