#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

void backtrack(int r, int n, vector<string>& board, 
               set<int>& col, set<int>& diag1, set<int>& diag2,
               vector<vector<string>>& res) {

    if (r == n) {
        res.push_back(board);
        return;
    }

    for (int c = 0; c < n; c++) {
        if (col.count(c) || diag1.count(r - c) || diag2.count(r + c))
            continue;

        board[r][c] = 'Q';
        col.insert(c); diag1.insert(r - c); diag2.insert(r + c);

        backtrack(r + 1, n, board, col, diag1, diag2, res);

        board[r][c] = '.';
        col.erase(c); diag1.erase(r - c); diag2.erase(r + c);
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    set<int> col, diag1, diag2;
    backtrack(0, n, board, col, diag1, diag2, res);
    return res;
}

int main() {
    int n = 4;
    auto ans = solveNQueens(n);
    for (auto &sol : ans) {
        for (auto &row : sol) cout << row << endl;
        cout << endl;
    }
}
