#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DNS_PORT 53
#define DNS_SERVER "8.8.8.8"

void send_dns_query(char* ip, char* query) {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(DNS_PORT);
    inet_pton(AF_INET, ip, &server.sin_addr);

    sendto(sock, query, strlen(query), 0, (struct sockaddr*)&server, sizeof(server));

    char buffer[65507];
    recvfrom(sock, buffer, 65507, 0, NULL, NULL);

    close(sock);
}

int main() {
    char ip[] = "192.168.1.1";
    char query[] = "example.com";

    while (1) {
        for (int i = 0; i < 100; i++) {
            send_dns_query(ip, query);
            usleep(1000);  // 1 ms delay
        }
    }

    return 0;
}