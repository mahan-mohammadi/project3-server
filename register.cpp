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


Register::Register(string packet){
	stringstream ss(packet);
	string temp , fname , lname , dname , birthdaydate , nid , uid , pass , phoneNum;

	std::getline(ss , temp , ':' );
	std::getline(ss , fname , ':' );
	std::getline(ss , lname , ':' );
	std::getline(ss , dname , ':' );
	std::getline(ss , birthdaydate , ':' );
	std::getline(ss , nid , ':' );
	std::getline(ss , uid , ':');
	std::getline(ss , pass , ':');
	std::getline(ss , phoneNum);

	Date birthday(birthdaydate);

	stringstream nids(nid);
	int numberid;
	nids >> numberid;
    sender = User(fname, lname, birthday, numberid, uid, pass, phoneNum , dname);
	
}