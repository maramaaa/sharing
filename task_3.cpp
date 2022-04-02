#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, l, r, c, s=0;
    cin >> n >> m;
    vector <int> d(n+1, 0);
    for (int i = 0; i < m; i++){
        cin >> l >> r >> c;
        for (int days = l; days <= r; days++){
            if (d[days] < c) d[days] = c;
        }
    }
    for (int i = 1; i <= n; i++) s += d[i];
    cout << s;
}

