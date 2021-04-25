#include <bits/stdc++.h>

using namespace std;

int n, m;
typedef vector<int> vt;
typedef pair<int, int> ii;
typedef vector<vt> vvt;

vvt dp = vvt(1000, vt(1001, 0));
vvt bt = vvt(1000, vt(1001, 0));
vector<ii> data = vector<ii>(1001, ii(0, 0));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif
    cin >> n >> m;
    for (int i = 1;i <= n;++ i) {
        cin >> data[i].first;
    }
    for (int i = 1;i <= n;++ i) {
        cin >> data[i].second;
    }
    for (int i = 0;i <= m;++ i) dp[0][i] = 0;

    for (int i = 1;i <= n;++ i) {
        for (int j = 0;j <= m;++ j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= data[i].first && dp[i - 1][j - data[i].first] + data[i].second > dp[i][j]) {
                dp[i][j] = dp[i - 1][j - data[i].first] + data[i].second;
            }
        }
    }
    // cout << dp[n][m] << "\n";
    while (n != 0) {
        if (dp[n][m] != dp[n - 1][m]) {
            cout << n << " ";
        }
        m -= data[n].first;
        n --;
    }
    return 0;
}