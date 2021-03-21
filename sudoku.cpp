#include <bits/stdc++.h>

/**
 * input
3 0 6 5 0 8 4 0 0 
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0
*/

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
vector<vector<int>> matrix(9, vector<int>(9, 0));

int solved = 0;

void input() {
    for (int i = 0;i < 9;++ i) {
        for (int j = 0;j < 9;++ j) {
            cin >> matrix[i][j];
        }
    }
}

void print_sudoku() {
    for (int i = 0;i < 9;++ i) {
        for (int j = 0;j < 9;++ j) cout << matrix[i][j] << " ";
        cout <<"\n";
    }
}

bool check_sudoku(int i, int j, int value) {
    for (int y = 0;y < 9;++ y) 
        if (matrix[i][y] == value) return false;
    for (int x = 0;x < 9;++ x) 
        if (matrix[x][j] == value) return false;
    i /= 3;
    j /= 3;
    for (int x = i * 3;x < i * 3 + 3;++ x) {
        for (int y = j * 3;y < j * 3 + 3;++ y) {
            if (matrix[x][y] == value) return false;
        }
    } 
    return true;
}

ii find_zero() {
    for (int i = 0;i < 9;++ i) {
        for (int j = 0;j < 9;++ j) {
            if (matrix[i][j] == 0) return ii(i, j);
        }
    }
    return ii(-1, -1);
}

void sol_sudoku() {
    ii dc = find_zero();
    if (dc.first == -1) {
        cout << "Solved\n";
        print_sudoku();
        exit(0);
    }
    for (int v = 1;v <= 9;++ v) {
        if (check_sudoku(dc.first, dc.second, v)) {
            matrix[dc.first][dc.second] = v;
            sol_sudoku();
            matrix[dc.first][dc.second] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif
    input();
    print_sudoku();
    sol_sudoku();
    cout << "Can't solve";
    return 0;
}