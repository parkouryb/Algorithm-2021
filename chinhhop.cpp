#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> a = vector<int>(20, 0);
vector<bool> fre = vector<bool>(20, true);

void chinhhop(int i) {
    if (i > k) {
        for (int j = 1;j <= k;++ j) cout << a[j] << " ";cout << "\n";
    }
    else {
        for (int j = 1;j <= n;++ j) {
            if (fre[j]) {
                fre[j] = false;
                a[i] = j;
                chinhhop(i + 1);
                fre[j] = true;
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
    cin >> n >> k;
    chinhhop(1);
    return 0;
}