function solveNQueens(n) {
    const res = [];
    const board = Array.from({ length: n }, () => Array(n).fill("."));
    const col = new Set(), diag1 = new Set(), diag2 = new Set();

    function backtrack(r) {
        if (r === n) {
            res.push(board.map(row => row.join("")));
            return;
        }

        for (let c = 0; c < n; c++) {
            if (col.has(c) || diag1.has(r - c) || diag2.has(r + c)) continue;

            board[r][c] = "Q";
            col.add(c); diag1.add(r - c); diag2.add(r + c);

            backtrack(r + 1);

            board[r][c] = ".";
            col.delete(c); diag1.delete(r - c); diag2.delete(r + c);
        }
    }

    backtrack(0);
    return res;
}

console.log(solveNQueens(4));
