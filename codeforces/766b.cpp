#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector <int> l(n, 0);

    for(int i = 0; i < n; i++)
        cin >> l[i];

    sort(l.begin(), l.end());

    for(int i = 1; i < n - 1; i++)
        if(l[i - 1] + l[i] > l[i + 1]) {
            cout << "YES\n";
            return 0;
        }

    cout << "NO\n";
    return 0;
}
