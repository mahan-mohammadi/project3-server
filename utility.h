#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <iostream>
#include "protocol.h"
#include "user.h"
using namespace std;

string listenToSocket();
Protocol whatProccess(string);
void makeAcc(User);
void sendAPacket(string);


#endif