#ifndef USER_H
#define USER_H

#include <string>
#include "Person.h"

using namespace std;

class User : public Person {
private:
    int numid;
    string messangerID; 
    string password;
    string phoneNumber; 
    string displayName;

public:
    User();

    User(string firstName, string familyName, Date birthday,
        int id, string msgID, string pwd,string phone, string display);

    // Setters
    void setID(int id);
    void setMessangerID(string msgID);
    void setPass(string pwd);
    void setPhoneNumber(string phone);
    void setDisplayName(string display);

    // Getters
    int getID();
    string getMessangerID(); 
    string getPassword();
    string getPhoneNumber();
    string getDisplayName();
};

#endif
