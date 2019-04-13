#include <bits/stdc++.h>

using namespace std;

int make(vector <int> &p, int i, int a, int b) {
    if(i == p.size())
        return abs(a - b);

    if((a + p[i]) - b <= 5)
        return make(p, i + 1, a + p[i], b);
    else if((b + p[i]) - a <= 5)
        return make(p, i + 1, a, b + p[i]);
    else return 10;
}

int main() {
    int t;
    cin >> t;

    for(int y = 0; y < t; y++) {
        int n, r;
        cin >> n;

        vector <int> p(n, 0);

        for(int i = 0; i < n; i++)
            cin >> p[i];

        r = make(p, 0, 0, 0);

        if(r <= 5)
            cout << "Feliz Natal!\n";
        else
            cout << "Ho Ho Ho!\n";

        p.clear();
    }

    return 0;
}
