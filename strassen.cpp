#include <bits/stdc++.h>

using namespace std;

int n = 4;
vector<vector<int>> as, bs, cs;
typedef vector<int> vt;
typedef vector<vt> vvt;
void printMatrix(vector<vector<int>> x) {
    for (int i = 0;i < x.size();++ i) {
        for (int j = 0;j < x[i].size();++ j) cout << x[i][j] << " ";
        cout << "\n";
    }
}
vvt plusMatrix(vvt a, vvt b) {
    vvt res = vvt(a.size(), vt(a.size(), 0));
    for (int i = 0;i < a.size();++ i) {
        for (int j = 0;j < a[i].size();++ j) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
    return res;
}

vvt minusMatrix(vvt a, vvt b) {
    vvt res = vvt(a.size(), vt(a.size(), 0));
    for (int i = 0;i < a.size();++ i) {
        for (int j = 0;j < a[i].size();++ j) {
            res[i][j] = a[i][j] - b[i][j];
        }
    }
    return res;
}

void input() {
    cout << n << "\n";
    for (int i = 0;i < n;++ i) {
        as.push_back(vector<int>(n, 0));
        for (int j = 0;j < n;++ j) {
            cin >> as[i][j];
        }
    }
    for (int i = 0;i < n;++ i) {
        bs.push_back(vector<int>(n, 0));
        for (int j = 0;j < n;++ j) {
            cin >> bs[i][j];
        }
    }
}

vector<vvt> splitMatrix(vvt a) {
    int half = a.size() / 2;
    vector<vvt> result;
    for (int i = 0;i < 4;++ i) {
        result.push_back(vector<vector<int>>(half, vector<int>(half, 0)));
    }

    for (int i = 0;i < a.size();++ i) {
        for (int j = 0;j < a[i].size();++ j) {
            int index = (i / half) * 2 + (j / half);
            int I = (i - ((index>>1)&1) * half);
            int J = (j - ((index>>0)&1) * half);
            result[index][I][J] = a[i][j];
        }
    }
    return result;
}

vvt multiStrassen(vector<vector<int>> sa, vector<vector<int>> sb) {
    if (sa.size() == 1) {
        return vvt(sa.size(), vt(sa.size(), sa[0][0] * sb[0][0]));
    }
    vvt res = vvt(sa.size(), vt(sa.size(), 0));
    vector<vvt> a = splitMatrix(sa);
    vector<vvt> b = splitMatrix(sb);
    vvt p1 = multiStrassen(a[0], minusMatrix(b[1], b[3]));
    vvt p2 = multiStrassen(plusMatrix(a[0], a[1]), b[3]);
    vvt p3 = multiStrassen(plusMatrix(a[2], a[3]), b[0]);
    vvt p4 = multiStrassen(a[3], minusMatrix(b[2], b[0]));
    vvt p5 = multiStrassen(plusMatrix(a[0], a[3]), plusMatrix(b[0], b[3]));
    vvt p6 = multiStrassen(minusMatrix(a[1], a[3]), plusMatrix(b[2], b[3]));
    vvt p7 = multiStrassen(minusMatrix(a[0], a[2]), plusMatrix(b[0], b[1]));

    vvt c11, c12, c21, c22;
    vector<vvt> c;
    for (int i = 0;i < 4;++ i) {
        c.push_back(vvt(a.size(), vt(a.size(), 0)));
    }

    c[0] = plusMatrix(minusMatrix(plusMatrix(p5, p4), p2), p6);
    c[1] = plusMatrix(p1, p2);
    c[2] = plusMatrix(p3, p4);
    c[3] = minusMatrix(minusMatrix(plusMatrix(p1, p5), p3), p7);

    int half = sa.size() / 2;
    for (int i = 0;i < sa.size();++ i) {
        for (int j = 0;j < sa[i].size();++ j) {
            int index = (i / half) * 2 + (j / half);
            int I = (i - ((index>>1)&1) * half);
            int J = (j - ((index>>0)&1) * half);
            res[i][j] = c[index][I][J];
        }
    }
    return res;
}


  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif
    input();
    vvt c = vvt(as.size(), vt(as.size(), 0));
    c = multiStrassen(as, bs);
    printMatrix(c);

    // print(a);
    // vector<vvt> res = splitMatrix(as);
    // vector<vvt> res1 = splitMatrix(res[0]);

    // for (int i = 0;i < 4;++ i) {
    //         printMatrix(res[i]);
    // }    
    return 0; 
}