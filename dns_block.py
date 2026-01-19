import socket
from threading import Thread
import time

# DNS server IP
dns_server = "8.8.8.8"

def send_dns_query(ip, port, query):
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.sendto(query, (ip, port))
    data, addr = sock.recvfrom(65507)
    sock.close()
    return data

def dns_amplification_defense():
    while True:
        # Example: 100 queries per second
        for i in range(100):
            send_dns_query("192.168.1.1", 53, b"example.com")

time.sleep(1)
Thread(target=dns_amplification_defense).start()