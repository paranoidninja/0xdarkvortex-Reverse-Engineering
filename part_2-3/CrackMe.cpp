//Author : Paranoid Ninja
//Email  : paranoidninja@protonmail.com

#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <ws2tcpip.h>

void VerifyKey(char* Key, char* buffer) {

	char KeyValue[8] = "";
	WSADATA version;
	WSAStartup(MAKEWORD(2,2), &version);
	SOCKET my_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	sockaddr_in my_address;
	my_address.sin_family = AF_INET;
	my_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	my_address.sin_port = htons(8080);
	connect(my_socket, (SOCKADDR*)&my_address, sizeof(my_address));
	send(my_socket, Key, strlen(Key)+1, 0);
	recv(my_socket, KeyValue, 8, 0);
	if (strcmp(KeyValue, "Valid\n") == 0) {
		strcat(buffer, "[+] Correct Password");
	}
	else {
		strcat(buffer, "[-] Invalid Password");
	}
	closesocket(my_socket);
	WSACleanup();
}

int main(int argc, char* argv[]) {

	if (argc != 2) {
		printf("Help:\n%s <10 character serial key>\n", argv[0]);
	}

	else {
		int KeyLen = strlen(argv[1]);
		if ((KeyLen > 10 || KeyLen < 10)) {
			printf("[-] Invalid Key Length. Password must be of 10 characters\n");
		}
		else {
			char buffer[21] = "";
			VerifyKey(argv[1], buffer);
			printf("%s",buffer);
			memset(buffer, 0, sizeof(buffer));
		}
	}


	return 0;
}
