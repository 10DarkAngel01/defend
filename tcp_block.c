#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_TCP_CONNECTIONS 100
int tcp_connections[256][256][256][256] = {0};  // IP address storage

void log_connection(char* ip) {
    int a = (ip[0] - '0') * 256 * 256 * 256;
    int b = (ip[1] - '0') * 256 * 256;
    int c = (ip[2] - '0') * 256;
    int d = (ip[3] - '0');

    tcp_connections[a][b][c][d]++;
    printf("[LOG] IP %s has %d TCP connections\n", ip, tcp_connections[a][b][c][d]);
}

int is_allowed(char* ip) {
    int a = (ip[0] - '0') * 256 * 256 * 256;
    int b = (ip[1] - '0') * 256 * 256;
    int c = (ip[2] - '0') * 256;
    int d = (ip[3] - '0');

    if (tcp_connections[a][b][c][d] >= MAX_TCP_CONNECTIONS) {
        return 0;
    }
    return 1;
}

int main() {
    char ip[] = "192.168.1.1";

    for (int i = 0; i < 1000; i++) {
        log_connection(ip);
        usleep(1000);  // 1 ms delay
    }

    return 0;
}