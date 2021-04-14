#include <bits/stdc++.h>

using namespace std;

int n, m;
typedef vector<int> vt;
typedef pair<int, int> ii;
typedef vector<vt> vvt;

vvt dp = vvt(1000, vt(1000, 0));
vector<ii> data = vector<ii>(1000, ii(0, 0));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif
    cin >> n >> m;
    for (int i = 0;i < n;++ i) {
        cin >> data[i].first >> data[i].second;
    }

    for (int i = 0;i < n;++ i) {
        
    }

    for (int i = 0;i < n;++ i) {
        cout << data[i].first << " " << data[i].second << "\n";
    }
    return 0;
}