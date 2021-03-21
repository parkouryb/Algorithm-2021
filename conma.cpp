#include <bits/stdc++.h>

using namespace std;

const int nmax = 1000 + 7;
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2};
int dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
int n = 5;
vector<vector<int>> matrix(n, vector<int>(n, 0));

void print() {
    for (vector<int> x: matrix) {
        for (int r: x) {
            cout << r << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool canGo(int x, int y, int lRange, int rRange) {
    return x >= lRange && x <= rRange
        && y >= lRange && y <= rRange
        && matrix[x][y] == 0;
}

void sol_horse(int i, int x, int y) {
    if (i > n * n) {
        print();
    }
    else {
        for (int j = 0;j < 8;++ j) {
            int u = x + dx[j];
            int v = y + dy[j];
            if (canGo(u, v, 0, n - 1)) {
                matrix[u][v] = i;
                sol_horse(i + 1, u, v);
                matrix[u][v] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    // freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif
    int x0 = 0, y0 = 0;
    matrix[x0][y0] = 1;
    sol_horse(2, x0, y0);
    return 0;
}