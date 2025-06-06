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



string listenToSocket(){

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;


    bind(serverSocket, (struct sockaddr*)&serverAddress,
         sizeof(serverAddress));

    listen(serverSocket, 5);

    int clientSocket
        = accept(serverSocket, nullptr, nullptr);

    char buffer[1024] = { 0 };
    recv(clientSocket, buffer, sizeof(buffer), 0);
    cout << buffer << endl;
    string text = buffer;
    
    close(serverSocket);

    return buffer;
}


Protocol whatProccess(string text){
    stringstream ss(text);
    string proto;
    getline(ss , proto , ':'); // TODO shouble to change the code so it doesnt use enum anymore just defines
     
    for(int i=0 ; i< sizeof(protocolMap) / sizeof(protocolMap[0] ; i++)){
        if(protocolMap[i] == proto) {
            return (Protocol)i;
        }
    }
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


