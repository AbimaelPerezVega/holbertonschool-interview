#!/usr/bin/python3

"""
Log Parsing Script

Reads lines from stdin and processes them to compute:
- The total file size from valid log entries.
- The count of different HTTP status codes (200, 301, 400, 401, 403, 404, 405, 500).

The script prints statistics:
- After processing every 10 valid lines.
- Upon receiving a keyboard interrupt (CTRL + C).
- After processing all input if fewer than 10 lines exist.

Expected log format:
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>

If the format does not match, the line is skipped.
"""

import sys
import signal

# Dictionary to store counts of specific HTTP status codes
status_counts = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

# Variable to store the total file size
total_size = 0

# Line counter
line_count = 0


def signal_handler(sig, frame):
    """
    Handles keyboard interruption (CTRL + C).
    Prints statistics before exiting the program.
    """
    print_statistics()
    sys.exit(0)


def print_statistics():
    """
    Prints accumulated statistics including total file size and count of each status code.
    Only prints status codes that have appeared at least once.
    """
    if total_size > 0:
        print(f"File size: {total_size}")

    for code in sorted(status_counts.keys()):
        if status_counts[code] > 0:
            print(f"{code}: {status_counts[code]}")


def process_line(line):
    """
    Processes a single log line, extracts relevant data, and updates statistics.

    Args:
        line (str): A single log entry from stdin.

    Returns:
        bool: True if the line was successfully processed, False otherwise.
    """
    global total_size, line_count

    parts = line.strip().split()

    # Ensure the line has at least 7 parts
    if len(parts) < 7:
        return False

    try:
        # Extract necessary fields
        ip = parts[0]
        date = parts[2]  # Not used, but ensures correct format
        request = parts[3] + " " + parts[4] + " " + parts[5]
        status_code = int(parts[6])
        file_size = int(parts[7])
    except (ValueError, IndexError):
        return False  # Ignore lines with incorrect formatting

    # Validate request format
    if request != '"GET /projects/260 HTTP/1.1"':
        return False

    # Update status count if it is in the valid list
    if status_code in status_counts:
        status_counts[status_code] += 1

    # Update total file size
    total_size += file_size

    line_count += 1
    return True


def main():
    """
    Reads log lines from stdin, processes them, and prints statistics
    after every 10 valid lines or upon a keyboard interruption.
    Ensures statistics are printed at the end if fewer than 10 lines exist.
    """
    global line_count

    # Register signal handler for keyboard interruption
    signal.signal(signal.SIGINT, signal_handler)

    try:
        for line in sys.stdin:
            process_line(line)
            if line_count % 10 == 0 and line_count > 0:
                print_statistics()

    except Exception as e:
        print(f"Error: {e}", file=sys.stderr)

    # Ensure final statistics are printed for remaining lines
    if line_count % 10 != 0:
        print_statistics()


if __name__ == "__main__":
    main()
