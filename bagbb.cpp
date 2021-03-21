#include <bits/stdc++.h>

using namespace std;

/**
input: n, m, sau do n dong: phan tu dau tien la value
phan tu thu 2 la weight.
5 15
12 4
2 2
1 1
1 2
4 10
*/

int n, m;
typedef pair<double, double> ii;
vector<ii> pack;
vector<int> saved = vector<int>(100, 0);
vector<int> savex = vector<int>(100, 0);
int best = 0, sumV(0), sumW(0);

void input() {
    cin >> n >> m;
    for (int i = 0;i < n;++ i) {
        int x, y;
        cin >> x >> y;
        pack.push_back(ii(x, y));
    }

}

void bag(int i) {
    if (i == n) {
        if (best < sumV) {
            best = sumV;
            for (int j = 0;j < n;++ j) {
                saved[j] = savex[j]; 
            }
        }
    }
    else {
        if (sumV + pack[i].second * ((m - sumW) / pack[i].first) < best) return;
        for (int j = (m - sumW) / pack[i].first;j >= 0;-- j) {
            sumW += pack[i].first * j;
            sumV += pack[i].second * j;
            savex[i] = j;
            bag(i + 1);
            sumW -= pack[i].first * j;
            sumV -= pack[i].second * j;
        }
    }
}

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return ((double)(a.second * b.first) > (double)(b.second * a.first)); 
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif
    input();
    sort(pack.begin(), pack.end(), sortbysec);
    for (ii x: pack) cout << x.first << " " << x.second << "\n";
    bag(0);
    cout << best << "\n";
    for (int i = 0;i < n;++ i) cout << saved[i] << " "; 
    return 0;
} 