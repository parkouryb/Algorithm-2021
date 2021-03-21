#include <bits/stdc++.h>

using namespace std;

const int nmax = 1000 + 7;
int n = 5;
vector<vector<int>> matrix(nmax, vector<int>(nmax + 7, 0));
vector<bool> cols(nmax, false);
vector<bool> diagonal1(nmax, false);
vector<bool> diagonal2(nmax, false);
int dem = 0;

void print() {
    for (int i = 1;i <= n;++ i) {
        for (int j = 1;j <= n;++ j) {
            if (matrix[i][j] == 1) {
                cout << j;
                break;
            }
        }
        cout << " ";
    }
    cout << "\n";
}

void sol_queens(int i) {
    if (i > n) {
        ++ dem;
        print();
        // exit(0);
    }
    else {
        for (int j = 1;j <= n;++ j) {
            if (!cols[j] && !diagonal1[i - j + n] && !diagonal2[i + j - 1]) {
                matrix[i][j] = 1;
                cols[j] = true;
                diagonal1[i - j + n] = true;
                diagonal2[i + j - 1] = true;
                sol_queens(i + 1);
                matrix[i][j] = 0;
                cols[j] = false;
                diagonal1[i - j + n] = false;
                diagonal2[i + j - 1] = false;
            }
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
    cin >> n;
    sol_queens(1);
    return 0;
}