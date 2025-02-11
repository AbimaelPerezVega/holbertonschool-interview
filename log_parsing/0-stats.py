#!/usr/bin/env python3

import sys
import signal

# Dictionary to store file sizes and status code counts
file_sizes = []
status_counts = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

def signal_handler(sig, frame):
    print_statistics()
    sys.exit(0)

def print_statistics():
    total_size = sum(file_sizes)
    if total_size > 0:
        print(f"File size: {total_size}")

    for code in sorted(status_counts.keys()):
        count = status_counts[code]
        if count > 0:
            print(f"{code}: {count}")

def process_line(line):
    parts = line.strip().split()
    if len(parts) != 7:
        return False

    ip, date, request, status, size = parts

    if not request.startswith("GET /projects/260 HTTP/1.1"):
        return False

    try:
        status_code = int(status)
        file_size = int(size)
    except ValueError:
        return False

    if status_code in status_counts:
        status_counts[status_code] += 1

    file_sizes.append(file_size)
    return True

def main():
    line_count = 0

    signal.signal(signal.SIGINT, signal_handler)

    for line in sys.stdin:
        if process_line(line):
            line_count += 1
            if line_count % 10 == 0:
                print_statistics()

if __name__ == "__main__":
    main()
