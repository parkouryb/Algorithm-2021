#include <bits/stdc++.h>

using namespace std;

int n;
int a[20];

void nhiphan(int i) {
    if (i > n) {
        for (int j = 1;j <= n;++ j) cout << a[j];cout << "\n";
    }
    else {
        for (int j = 0;j <= 1;++ j) {
            a[i] = j;
            nhiphan(i + 1);
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
    memset(a, 0, sizeof(a));
    nhiphan(1);
    return 0;
}