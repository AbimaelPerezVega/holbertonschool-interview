#!/usr/bin/python3
import sys


def is_safe(board, row, col):
    """ Check if it's safe to place a queen at board[row][col] """
    for r in range(row):
        c = board[r]
        if c == col or abs(r - row) == abs(c - col):
            return False
    return True


def solve_nqueens(N, board, row, solutions):
    """ Backtracking function to solve N Queens problem """
    if row == N:
        solutions.append(list(board))
        return

    for col in range(N):
        if is_safe(board, row, col):
            board[row] = col
            solve_nqueens(N, board, row + 1, solutions)
            board[row] = -1


def nqueens(N):
    """ Main function to solve the N Queens problem """
    if not isinstance(N, int):
        print("N must be a number")
        sys.exit(1)
    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    board = [-1] * N
    solutions = []
    solve_nqueens(N, board, 0, solutions)

    for solution in solutions:
        print([[i, solution[i]] for i in range(N)])


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    nqueens(N)
