#include "utility.h"
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
