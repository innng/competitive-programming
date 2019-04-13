#include <bits/stdc++.h>

using namespace std;

int find(string a, string b) {
    vector <int> v(b.length(), 0);

    int i = 0, j = 0;

    for(i = 0; i < b.length(); i++) {
        for(j = 0; j < a.length(); j++) {
            if(b[i] == a[j])
                v[i] += 1;
        }
    }

    int max = v[0];
    for(i = 1; i < v.size(); i++)
        if(max < v[i])
            max = v[i];

    return max;
}

int main() {
    int t;
    cin >> t;

    for (int y = 0; y < t; y++) {
        string a, b;
        cin >> a >> b;

        cout << find(a, b) << '\n';
    }

    return 0;
}
