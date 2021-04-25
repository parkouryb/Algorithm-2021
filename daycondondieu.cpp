#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;
typedef pair<int, int> ii;
vector<ii> tree = vector<ii>(1000000 + 7, ii(0, -1));
vector<int> backtrack;

void update(int x, ii val) {
    for (int i = x;i <= 1000000;i += i&-i) {
        tree[i] = val;
    }
}

ii get(int x) {
    ii res(0, -1);
    for (int i = x;i > 0;i -= i&-i) {
        if (tree[i].first > res.first) {
            res = tree[i];
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
    // #endif
    cin >> n;
    backtrack = vector<int>(n, -1);
    for (int i = 0;i < n;++ i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    ii res(0, 0);
    int vv = 0;
    for (int i = 0;i < n;++ i) {
        ii val = get(a[i] - 1);
        backtrack[i] = val.second;
        // cout << val.first << " " << val.second << "\n";
        val.first += 1;
        val.second = i;
        if (val.first > res.first) {
            res = val;
            vv = i;
        }
        update(a[i], val);
        // cout << val.first << " " << val.second << "\n";
    }
    vector<int> ok;
    while (res.second != -1) {
        ok.push_back(a[res.second]);
        res.second = backtrack[res.second];
    }
    // cout << res << "\n";
    reverse(ok.begin(), ok.end());
    for (int i = 0;i < ok.size();++ i) {
        cout << ok[i] << " ";
    }
    return 0;
}