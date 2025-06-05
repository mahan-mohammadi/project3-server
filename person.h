#ifndef PERSON_H // Header guard to prevent multiple inclusions
#define PERSON_H

#include <string>
#include "date.h" 

class Person {
protected:
    std::string firstName;
    std::string familyName;
    Date birthdayDate;

public:
    Person();

    Person(std::string fn, std::string ln, Date bd);

    std::string getFirstName();

    void setFirstName(std::string fn);

    void setFamilyName(std::string ln); 

    std::string getFamilyName();

    Date getBirthday();

    void setBirthday(Date bd);
};

#endif 