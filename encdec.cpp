#include <iostream>
#include "encdec.h"

using namespace std;


encdec::encdec(string text, int key) {
	this->text = text;
	this->key = key;
}

void encdec::encrypt()
{
    for (int i = 0; '\0' != text[i]; i++)
        text[i] -= key;
    }

void encdec::decrypt()
{
    for (int i = 0; '\0' != text[i]; i++)
        text[i] += key;
}
   

void encdec::setKey(int k) {
    key = k;
}

int encdec::getKey() {
    return key;
}

void encdec::setString(string s) { 
    text = s;
}

string encdec::getString() {
    return text;
}

