#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> c = vector<vector<int>>(100, vector<int>(100, INT_MAX - 7)); 
vector<bool> fre = vector<bool>(100, true);
int best(INT_MAX - 7), sum(0);
vector<int> trace = vector<int>(100, 0);
vector<int> t = vector<int>(100, 0);

void input() {
    cin >> n;
    for (int i = 0;i < n;++ i) {
        for (int j = 0;j < n;++ j) cin >> c[i][j];
    }
}

void branchBound(int i) {
    if (i == n) {
        sum += c[t[i - 1]][0];
        if (best > sum) {
            best = sum;
            trace = t;
        }
        sum -= c[t[i - 1]][0];
    }
    else {
        for (int j = 0;j < n;++ j) {
            if (fre[j] == false) continue;
            int u = t[i - 1];
            if (u == j) continue;
            if (sum + c[u][j] >= best) continue;
            fre[j] = false;
            sum += c[u][j];
            t[i] = j;
            // cout << u << " -> " << j << " = " << sum << "\n";
            branchBound(i + 1);
            sum -= c[u][j];
            fre[j] = true;
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
    int u = 0;
    t[0] = u;
    fre[u] = false;
    branchBound(1);
    cout << best << "\n";
    for (int i = 0;i < n;++ i) cout << trace[i] + 1 << " ";
    return 0;
} 