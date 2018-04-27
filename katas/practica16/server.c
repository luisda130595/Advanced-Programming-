#include <stdio.h>
#include <sys/socket.h>
#include <string.h>

int main(){

	struct sockaddr serverAddress;
	int serverSocket;
	int clientSocket;
	char *hello = "Hello World";

	serverSocket = socket(PF_INET,SOCK_STREAM,0);
	
	memset(&serverAddress, '0', sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htons(5000);
	serverAddress.sin_port = htons(5000);
	bind(serverSocket, (struct sockaddr *)&serverAddress, strlen(sizeof(serverAddress)));
	listen(serverSocket,10);
	
	while(1){
		clientSocket = accept(serverSocket, (struct sockaddr*)NULL, NULL);
		write(clientSocket,hello,strlen(hello));
		read(clientSocket, clientMsg, 1000);
		printf("El cliente dice %s\n", clientMsg);
		close(clientSocket);
	}

	return 0;
}