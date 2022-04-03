#include <iostream>
#include <string>
using namespace std;


int main(){
    int am[11]={0};
    int t, n, k, ch=0;
    string s;
    cin >> t;
    bool b = 1;
    for (int test = 0; test < t; test++){
        cin >> n >> k;
        for (int num = 0; num < n; num++) {
            cin >> s;
            for (int i = 0; i < k; i++) {
                if (s[i] == '1') am[i]++;
            }
        }
        for (int i = 0; i < k; i++){
            if (am[0] % 2 == 1 && i==0) ch = am[i];
            else if (am[i] % 2 == 1 && (ch!=am[i] or ch!=0)) {cout << "NO" << endl; b = 0; break;}
        }
        if (b) cout << "YES" << endl;
        int am[11]={0};
    }
}
