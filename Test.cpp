#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n-i; j++) {
            cout << " ";
        }
        char ch = 'A';
        for (int j = 0; j < i+1; j++) {
            cout << ch;
            ch++;
        }
        ch--;
        for (int j = 0; j < i; j++) {
            ch--;
            cout << ch;
            
        }
        for (int j = 1; j < n-i; j++) {
            cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    solve(n);
    return 0;
}