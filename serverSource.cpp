#include <iostream>
#include <winsock2.h>
#include <cstring>
#include <stdlib.h>
#include <Ws2tcpip.h>
#pragma comment(lib, "WS2_32")

//normally I wouldn't include this but I'm trying to focus on the network code 
//and not the syntax of the code without using this
using namespace std;

int main()
{
	WSADATA WSAData;
	SOCKET server, client;
	SOCKADDR_IN serverAddr, clientAddr;
	int size = sizeof(serverAddr);
	char buffer[1024];
	char addressBuffer[1024];
	WSAStartup(MAKEWORD(2, 2), &WSAData);

	server = socket(AF_INET, SOCK_STREAM, 0);
	client = socket(AF_INET, SOCK_STREAM, 0);

	if (server < 0) {
		cout << "Error establishing socket." << endl;
		exit(1);
	}
	cout << "Socket has been established." << endl;

	serverAddr.sin_addr.s_addr = htons(INADDR_ANY);
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(1500);

	if (bind(client, (SOCKADDR*)& serverAddr, sizeof(serverAddr)) < 0)
	{
		cout << "There was an error binding the connection." << endl;
		return -1;
	}
	cout << "Listening for clients." << endl;

	listen(client, 1);

	cout << "Listening for connections " << endl;

	server = accept(client, (sockaddr*)& serverAddr, &size);

	if (server < 0)
	{
		cout << "Error on accepting client." << endl;
	}

	while (server > 0)
	{
		strcpy_s(buffer, "Server connected");
		send(server, buffer, strlen(buffer), 0);
		cout << "Connected with client." << endl;
		/*
		while (*buffer != '$')
		{
			recv(server, buffer, strlen(buffer), 0);
			cout << buffer << " ";
			if (*buffer == '!') {
				*buffer = '$';
			}
		}
		memset(&buffer, 0, sizeof(buffer));
		while (true)
		{
			cout << "\nServer: ";
			while (*buffer != '$') {
				cin >> buffer;
				send(server, buffer, strlen(buffer), 0);
				if (*buffer == '!') {
					send(server, buffer, strlen(buffer), 0);
					*buffer = '$';
				}
			}
			memset(&buffer, 0, sizeof(buffer));
			cout << "\nClient: ";
			while (*buffer != '$') {
				recv(server, buffer, strlen(buffer), 0);
				cout << buffer << " ";
				if (*buffer == '!') {
					*buffer = '$';
				}
			}
		}*/

		//cout << "Connection terminated " << InetNtop(serverAddr.sin_addr);
		closesocket(server);
		exit(1);
	}
	closesocket(client);
	return 0;

}