// C++ program to show the example of server application in
// socket programming
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include "register.h"
#include "protocol.h"
#include "user.h"
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;






int main()
{

    while(true){
    string packet;
    packet = listenToSocket();
    Protocol proto = whatProccess(packet);
    switch (proto)
    {
    case REG:
        Register reg(packet);
        makeAcc(reg.getSender());
        break;
    
    default:
        break;
    }
    return 0;
}



void makeAcc(User u){
    u.saveToFile();
    cout << "have registered the user" << endl;

}


