from collections import defaultdict
import time

# Track TCP connections per IP
tcp_connections = defaultdict(int)

def is_allowed(ip):
    if tcp_connections[ip] >= 100:
        return False
    return True

def log_connection(ip):
    tcp_connections[ip] += 1
    print(f"[LOG] IP {ip} has {tcp_connections[ip]} TCP connections")

# Example: 1000 connections in 1 second
for i in range(1000):
    log_connection("192.168.1.1")
    time.sleep(0.001)