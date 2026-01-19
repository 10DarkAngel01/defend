from collections import defaultdict
import time

# Track request count per IP
ip_requests = defaultdict(int)

def is_allowed(ip):
    if ip_requests[ip] >= 100:
        return False
    return True

def log_request(ip):
    ip_requests[ip] += 1
    print(f"[LOG] IP {ip} has {ip_requests[ip]} requests")

# Example: 1000 requests in 1 second
for i in range(1000):
    log_request("192.168.1.1")
    time.sleep(0.001)