#include <bits/stdc++.h>

using namespace std;

int n = 6, k = 3;
vector<int> muve;

int sum() {
    int sum = 0;
    for (int x: muve) sum += x;
    return sum;
}

void print() {
    for (int x: muve) cout << x << " ";
    cout << "\n";
}

void sol() {
    if (sum() == n) print();
    for (int i = 1;i <= k;++ i) {
        if (sum() + i > n) break;
        muve.push_back(i);
        sol();
        muve.pop_back();
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
    sol();
    return 0;
}