#include "utility.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <sstream>
using namespace std;

std::string listenToSocket() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2,2), &wsaData);

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (sockaddr*)&serverAddress, sizeof(serverAddress));
    listen(serverSocket, 5);

    SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);

    char *buffer = { 0 };
    recv(clientSocket, buffer, sizeof(buffer), 0);
    std::cout << buffer << std::endl;
    std::string text = buffer;

    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    return text;
}



Protocol whatProccess(string text){
    stringstream ss(text);
    string proto;
    getline(ss , proto , ':'); // TODO shouble to change the code so it doesnt use enum anymore just defines
     
    for(int i=0 ; i< sizeof(protocolMap) / sizeof(protocolMap[0]) ; i++)
    {
        if(protocolMap[i] == proto) {
            return (Protocol)i;
        }
    }
}


void sendAPacket(std::string packet) {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2,2), &wsaData);

    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    connect(clientSocket, (sockaddr*)&serverAddress, sizeof(serverAddress));

    const char* message = packet.c_str();
    send(clientSocket, message, strlen(message), 0);

    std::cout << "send : " << message << std::endl;

    closesocket(clientSocket);
    WSACleanup();
}
