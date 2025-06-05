#include "Person.h"
#include "date.h"
#include <string>

Person::Person() {
    firstName = "";
    familyName = "";

}


Person::Person(std::string first, std::string last, Date birth) {
    firstName = first;
    familyName = last;
    birthdayDate = birth;
}

// Getter for first name
std::string Person::getFirstName() {
    return firstName;
}

// Setter for first name
void Person::setFirstName(std::string first) {
    firstName = first;
}

// Setter for family name
void Person::setFamilyName(std::string ln) {
    familyName = ln;
}

// Getter for family name
std::string Person::getFamilyName() {
    return familyName;
}

// Getter for birthday
Date Person::getBirthday() {
    return birthdayDate;
}

// Setter for birthday
void Person::setBirthday(Date bd) {
    birthdayDate = bd;
}