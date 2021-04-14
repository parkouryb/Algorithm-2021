#include <bits/stdc++.h>

using namespace std;

int getMin(vector<int> a, int l, int r) {
    if (l == r) return a[l];
    int mid = (l + r) / 2;
    return min(getMin(a, l, mid), getMin(a, mid + 1, r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif
    vector<int> a = {6, 4, 2, 3, 6, 4};
    cout << getMin(a, 0, a.size() - 1);

    return 0;
}