// client.cpp
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsaData;
    SOCKET sock = INVALID_SOCKET;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE] = { 0 };
    const char* message = "Hello from client";

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Failed to initialize Winsock" << std::endl;
        return -1;
    }

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        std::cerr << "Socket creation failed" << std::endl;
        WSACleanup();
        return -1;
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        std::cerr << "Connection to server failed" << std::endl;
        closesocket(sock);
        WSACleanup();
        return -1;
    }

    // Send message to server
    send(sock, message, strlen(message), 0);
    std::cout << "Message sent to server: " << message << std::endl;

    // Receive response from server
    recv(sock, buffer, BUFFER_SIZE, 0);
    std::cout << "Message from server: " << buffer << std::endl;

    // Clean up
    closesocket(sock);
    WSACleanup();

    return 0;
}
