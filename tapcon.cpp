#include <bits/stdc++.h>

using namespace std;

int n, k;
vector <int> a = vector<int>(20, 0);
void tapcon(int i) {
    if (i > k) {
        for (int j = 1;j <= k;++ j) cout << a[j] << " ";cout << "\n";
    }
    else {
        for (int j = a[i - 1] + 1;j <= n;++ j) {
            a[i] = j;
            tapcon(i + 1);
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
    a[0] = 0;
    tapcon(1);
    return 0;
}