#include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int> a, int l, int r, int cmp) {
    while (l < r - 1) {
        int mid = (l + r) / 2;
        if (a[mid] == cmp) return mid;
        else {
            if (a[mid] > cmp) 
                r = mid;
            else l = mid;
        }
    }
    if (a[l] == cmp) return l;
    else if (a[r] == cmp) return r;
    else return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif
    vector<int> a = vector<int>(5, 0);
    for (int i = 0;i < 5;++ i)
        a[i] = (i * 24 + 13 / 3) % 23;

    for (int x: a) cout << x << " ";
    cout << "\n";
    cout << binary_search(a, 0, 4, 5);

    return 0;
}