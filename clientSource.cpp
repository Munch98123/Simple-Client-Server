#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <string>
#include <winsock2.h>
#include <Ws2tcpip.h>

#pragma comment(lib, "WS2_32")

using namespace std;

int main()
{
	//creates a windows socket
	WSADATA WSAData;
	//the socket itself
	SOCKET client;
	//socket information like IP address and port number
	SOCKADDR_IN address;
	char buffer[1024];

	//actually creates the soecket
	//1	-	first parameter is the IPV speicification, this one uses IPV4 code
	//2	-	second parameter is the type of connection, in this case it is sock_stream
	//this allows a connection between two distant devices through TCP
	//3	-	the third parameter is the protocol used which is mostly just set to 0
	client = socket(AF_INET, SOCK_STREAM, 0);

	if (client < 0) {
		cout << "\nError connecting." << endl;
		exit(1);
	}

	//makes the IP address we connect to the local host
	//This allows me to run both client and server on same device
	//Change the IP address to the device you want to be the server
	//the IP address needs to be on the same network though, this program does no forwarding
	InetPton(AF_INET, "127.0.0.1", &address.sin_addr.s_addr);

	//sets the address familt for the server to IPV4
	address.sin_family = AF_INET;

	address.sin_addr.s_addr = INADDR_ANY;

	//htons converts a u_short from host to TCP?IP network byte order
	//this line means that we connect to port xxxx, you can change this if the port isnt working
	address.sin_port = htons(1500);

	//finally we connect to the server with 3 parameters
	//1	-	The server socket we created earlier
	//2	-	The address information for the socket 
	//3	-	The size of the address information for the socket
	if (connect(client, (SOCKADDR*)& address, sizeof(address)) == 0)
		cout << "Connection to the server port number " << 5555 << endl;

	cout << "Connecting to the server." << endl;
	connect(client, (sockaddr*)& address, sizeof(address));
	cout << "Connected" << endl;

	cout << "Enter ! to end the connection" << endl;

	while (true) {
		/*
		cout << "CLient: ";
		while (*buffer != '!') {
			cin >> buffer;
			send(client, buffer, strlen(buffer), 0);
			if (*buffer == '!') {
				send(client, buffer, strlen(buffer), 0);
				break;
			}
		}
		memset(&buffer, 0, sizeof(buffer));
		while (*buffer != '!') {
			recv(client, buffer, strlen(buffer), 0);
			cout << buffer << " ";
			if (*buffer == '!') {
				break;
			}
		}
		if (*buffer == '!') {
			break;
		}*/
	}


}