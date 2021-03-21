#include <bits/stdc++.h>

using namespace std;

const int nmax = 1000 + 7;
int n = 5;
vector<int> a(n + 1, 0);
vector<int> sum(n + 1, 0);

void print(int k) {
    for (int i = 1;i <= k;++ i) cout << a[i] << " ";
    cout <<"\n";
}

void sol_number(int i) {
    for (int j = a[i - 1];j <= (n - sum[i - 1]) / 2;++ j) {
        a[i] = j;
        sum[i] = sum[i - 1] + j;
        sol_number(i + 1);
    }
    a[i] = n - sum[i - 1];
    print(i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    // freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif
    a[0] = 1;
    sol_number(1);
    return 0;
}