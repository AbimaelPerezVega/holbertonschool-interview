#!/usr/bin/python3

"""
Log Parsing Script

Reads lines from stdin and processes them to compute:
- The total file size from valid log entries.
- The count of different HTTP status codes (200, 301, 400, 401, 403, 404, 405, 500).

The script prints statistics:
- After processing every 10 valid lines.
- Upon receiving a keyboard interrupt (CTRL + C).
- After processing all input, even if the file is empty.

Expected log format:
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>

If the format does not match, the line is skipped.
"""

import sys
import signal
import re

# Regular expression pattern for valid log lines
log_pattern = re.compile(
    r'^(\S+) - \[.*?\] "GET /projects/260 HTTP/1.1" (\d{3}) (\d+)$'
)

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
    Always prints "File size: <total_size>" even if no lines were processed.
    """
    print(f"File size: {total_size}")
    for code in sorted(status_counts.keys()):
        if status_counts[code] > 0:
            print(f"{code}: {status_counts[code]}")


def process_line(line):
    """
    Processes a single log line using a regex pattern.
    Extracts status code and file size, updating statistics.

    Args:
        line (str): A single log entry from stdin.

    Returns:
        bool: True if the line was successfully processed, False otherwise.
    """
    global total_size, line_count

    match = log_pattern.match(line.strip())
    if not match:
        return False

    try:
        status_code = int(match.group(2))
        file_size = int(match.group(3))
    except ValueError:
        return False  # Ignore lines with incorrect formatting

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
    Ensures statistics are printed at the end, even if the file is empty.
    """
    global line_count

    # Register signal handler for keyboard interruption
    signal.signal(signal.SIGINT, signal_handler)

    try:
        for line in sys.stdin:
            if process_line(line) and line_count % 10 == 0:
                print_statistics()
    except Exception as e:
        print(f"Error: {e}", file=sys.stderr)

    # Ensure final statistics are printed, even if no lines were processed
    print_statistics()


if __name__ == "__main__":
    main()
