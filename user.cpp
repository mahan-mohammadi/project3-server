#include "user.h"

User::User()
    : Person(){
    numid = 0;
    messangerID = "";
    password = "";
    phoneNumber = "";
    displayName = "";
}

User::User(string firstName, string familyName, Date birthday,
    int id, string msgID, string pwd, string phone, string display) : Person(firstName, familyName, birthday){
    numid = id;
    messangerID = msgID;
    password = pwd;
    phoneNumber = phone;
    displayName = display;
}

void User::setID(int id) {
    numid = id;
}

void User::setMessangerID(string msgID) {
    messangerID = msgID;
}

void User::setPass(string pwd) {
    password = pwd;
}

void User::setPhoneNumber(string phone) {
    phoneNumber = phone;
}

void User::setDisplayName(string display) {
    displayName = display;
}

int User::getID() {
    return numid;
}

string User::getMessangerID() {
    return messangerID;
}

string User::getPassword() {
    return password;
}

string User::getPhoneNumber() {
    return phoneNumber;
}

string User::getDisplayName() {
    return displayName;
}