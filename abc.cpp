#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> t = vector<int>(101, 0);
vector<char> x = vector<char>(101, 'A');
vector<char> best = vector<char>(101, 'A');
int minC = 1000;

bool same(int i, int l) {
    int j = i - l;
    for (int k = 0;k < l;++ k) 
        if (x[i - k] != x[j - k]) return false;
    return true;
}

bool check(int i) {
    for (int l = 1;l <= i / 2; ++ l) 
        if (same(i, l)) 
            return false;
    return true;
}

void Try(int i) {
    if (i > n) {
        minC = t[n];
        best = x;
    }
    else {
        for (char j = 'A';j <= 'C';++ j) {
            x[i] = j;
            // cout << i << " " << j << " - " << t[i] << " " << check(i) << "\n";
            if (check(i)) {
                t[i] = (j == 'C') ? t[i - 1] + 1 : t[i - 1];
                if (t[i] + (n - i) / 4 < minC) 
                    Try(i + 1);
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
    for (int i = 0;i < (1<<n);++ i) {
        for (int j = n - 1;j >= 0;-- j) {
            cout << ((i>>j)&1);
        }
        cout << "\n";
    }
    // t[0] = 0;
    // minC = n;
    // Try(1);
    // for (int i = 1;i <= n;++ i) cout << best[i];
    return 0;
}