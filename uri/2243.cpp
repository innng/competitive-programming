#include <bits/stdc++.h>

using namespace std;

int find(vector <int> &w, vector <int> &p, int c, int h) {
    int d = 1;

    while(h != d && h != 0 && h > p[c - 1] && h > p[c - 1]) {
        if(
            ((c - d) >= 0 && (c + d) <= w.size() - 1) &&
            (w[c - d] >= (h - d) && w[c + d] >= (h - d)))
            d += 1;
        else {
            h -= 1;
            d = 1;
        }
    }

    return h;
}

int main() {
    int n, h = 0;
    cin >> n;

    vector <int> w(n, 0);
    vector <int> p(n, -1);

    for(int i = 0; i < w.size(); i++)
        cin >> w[i];

    w[0] = 1;
    w[n - 1] = 1;

    for(int i = 1; i < w.size() - 1; i++) {
        int j = w[i - 1] < w[i + 1] ? w[i - 1] : w[i + 1];
        int k = w[i] < j + 1 ? w[i] : j + 1;
        int l = k < i + 1 ? k : i + 1;
        w[i] = l < n - i + 1 ? l : n - i + 1;
    }

    for(int i = 0; i < w.size(); i++) {
        if(w[i] > h) {
            int r = find(w, p, i, w[i]);
            p[i] = r;

            if(r > h)
                h = r;
        }
    }

    cout << h <<'\n';

    return 0;
}
