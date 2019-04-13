#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n;
    cin >> n;

    do {
        vector <long long int> m(n, 0);

        for(long long int i = 0; i < n; i++)
            cin >> m[i];

        long long int s = 0;

        for(long long int i = m.size() - 1; i >= 0; i--) {
            s += m[i];
            for(long long int j = 0; j < i; j++) {
                m[j] += m[i];
            }
        }

        cout << s << '\n';

        cin >> n;
    } while(n != 0);
    return 0;
}
