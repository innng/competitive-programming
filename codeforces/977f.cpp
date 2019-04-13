#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector <int> num(n, 0);
    map <int, int> m;
    vector <int> r;

    for(int i = 0; i < n; i++) {
        cin >> num[i];
        m[num[i]] = max(0, m[num[i] - 1] + 1);
    }

    int max = m[num[0]], v;
    for(int i = 1; i < n; i++)
        if(m[num[i]] > max) {
            max = m[num[i]];
            v = num[i];
        }

    cout << max << '\n';

    if(max == 1) {
        cout << 1 << '\n';
        return 0;
    }

    for(int i = n - 1; i >= 0; i--) {
        if(num[i] == v) {
            r.push_back(i + 1);
            v -= 1;
        }
    }

    sort(r.begin(), r.end());

    for(int i = 0; i < r.size(); i++)
        cout << r[i] << ' ';

    cout << '\n';

    return 0;
}
