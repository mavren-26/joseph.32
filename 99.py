def solveNQueens(n):
    res = []
    board = [["."] * n for _ in range(n)]
    col = set()
    diag1 = set()  # r - c
    diag2 = set()  # r + c

    def backtrack(r):
        if r == n:
            res.append(["".join(row) for row in board])
            return

        for c in range(n):
            if c in col or (r - c) in diag1 or (r + c) in diag2:
                continue

            board[r][c] = "Q"
            col.add(c); diag1.add(r - c); diag2.add(r + c)
            backtrack(r + 1)
            board[r][c] = "."
            col.remove(c); diag1.remove(r - c); diag2.remove(r + c)

    backtrack(0)
    return res

print(solveNQueens(4))
