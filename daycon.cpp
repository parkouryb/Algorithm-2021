#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a = vector<int>(1000001, 0);
vector<int> l = vector<int>(1000001, 0);
vector<int> tree = vector<int>(1000001, 0);

void update(int x, int val) {
    for (int i = x;i <= 1000000;i += i&-i) 
        tree[i] = max(tree[i], val);
}

int get(int x) {
    int res = 0;
    for (int i = x;i > 0;i -= i&-i) 
        res = max(res, tree[i]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif
    cin >> n;
    for (int i = 0;i < n;++ i) cin >> a[i];
    int res = 0;
    for (int i = 0;i < n;++ i) {
        int val = get(a[i]) + 1;
        res = max(res, val);
        update(a[i], val);
    }
    cout << res;
    return 0;
}