#include <bits/stdc++.h>

using namespace std;

int n, x, y;
typedef vector<int> vt;
typedef vector<vt> vvt;
vvt matrix = vvt(128, vt(128, 0));
int cnt = 0;

void place(int x1, int y1, int x2,
           int y2, int x3, int y3) {
    ++ cnt;
    matrix[x1][y1] = cnt;
    matrix[x2][y2] = cnt;
    matrix[x3][y3] = cnt;
}

void fillFloor(int n, int x, int y) {
    if (n == 2) {
        ++ cnt;
        for (int i = 0;i < n;++ i) {
            for (int j = 0;j < n;++ j) {
                if (matrix[x + i][y + j] == 0) {
                    matrix[x + i][y + j] = cnt;
                }
            }
        }
        return;
    }
    int r, c;
    for (int i = x;i < x + n;++ i) {
        for (int j = y;j < y + n;++ j) {
            if (matrix[i][j] != 0) {
                r = i, c = j;
            }
        }
    }
    if (r < x + n / 2 && c < y + n / 2){
        fillFloor(n / 2, x, y);
        place(x + n / 2, y + (n / 2) - 1, x + n / 2,
              y + n / 2, x + n / 2 - 1, y + n / 2);
        fillFloor(n / 2, x, y + n / 2);
        fillFloor(n / 2, x + n / 2, y);
        fillFloor(n / 2, x + n / 2, y + n / 2);
    }
    else if (r >= x + n / 2 && c < y + n / 2) {
        fillFloor(n / 2, x + n / 2, y);
        place(x + (n / 2) - 1, y + (n / 2), x + (n / 2),
              y + n / 2, x + (n / 2) - 1, y + (n / 2) - 1);
        fillFloor(n / 2, x, y);
        fillFloor(n / 2, x, y + n / 2);
        fillFloor(n / 2, x + n / 2, y + n / 2);
    }
    else if (r < x + n / 2 && c >= y + n / 2) {
        fillFloor(n / 2, x, y + n / 2);
        place(x + n / 2, y + (n / 2) - 1, x + n / 2,
              y + n / 2, x + n / 2 - 1, y + n / 2 - 1);
        fillFloor(n / 2, x, y);
        fillFloor(n / 2, x + n / 2, y);
        fillFloor(n / 2, x + n / 2, y + n / 2);

    }
    else if (r >= x + n / 2 && c >= y + n / 2) {
        fillFloor(n / 2, x + n / 2, y + n / 2);
        place(x + (n / 2) - 1, y + (n / 2), x + (n / 2),
              y + (n / 2) - 1, x + (n / 2) - 1,
              y + (n / 2) - 1);
        fillFloor(n / 2, x + n / 2, y);
        fillFloor(n / 2, x, y + n / 2);
        fillFloor(n / 2, x, y);
    }

    return;
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif

    // cin >> n >> x >> y;
    n = 8, x = 0, y = 0;
    matrix[x][y] = -1;

    fillFloor(n, 0, 0);

    // matrix[x][y] = 0;

    for (int i = 0; i < n; i++) {    
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " \t";
        cout << "\n";
    }
    return 0;
} 