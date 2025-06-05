#ifndef ENCDEC_H
#define ENCDEC_H

#include <string>

using namespace std;

class encdec {
private:
    int key;
    string text;;

public:
    encdec(string, int);
    void encrypt();
    void decrypt();
    void setKey(int);
    int getKey();
    void setString(string);
    string getString();
};

#endif
