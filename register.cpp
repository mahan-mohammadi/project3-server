#include "register.h"
#include <sstream>
#include "user.h"
#include "encdec.h"

void Register::send() {
	stringstream ss;
	encdec encryption(sender.getPassword(), 5);
	encryption.encrypt();
	string encPass = encryption.getString();
	ss << "REG:" << sender.getFirstName() << ':' << sender.getFamilyName() << ':'
		<< sender.getDisplayName()  << ':' << sender.getBirthday().toString() << ':' << sender.getID() << ':' << sender.getMessangerID() << ':'
		<< encPass
		<< sender.getPhoneNumber();


	string message = ss.str();

}