// C++ program to show the example of server application in
// socket programming
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include "register.h"
#include "protocol.h"
#include "user.h"
#include <fstream>
#include "utility.h"

using namespace std;

string getLastid(){
    cout << "getting the num id..." << endl;
    fstream file("users.txt");
    string lastline;
    while(getline(file, lastline)){}
    stringstream ss(lastline);
    string id;
    ss >> id; 
    return id;    
}

void makeAcc(User u){
    u.saveToFile();
    cout << "have registered the user" << endl;

}

int main()
{

    while(true){
    string packet;
    packet = listenToSocket();
    Protocol proto = whatProccess(packet);
    switch (proto)
    {
    case REG:
     {   Register reg(packet);
        makeAcc(reg.getSender());
        break;}
    case LASTIDCALL:
        {string id = getLastid();
        sendAPacket(id);
        break;}
    default:
        break;
    }
  
}
  return 0;
}



