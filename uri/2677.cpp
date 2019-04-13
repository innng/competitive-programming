#include <bits/stdc++.h>

using namespace std;

vector <int> num;
int m[2000][2000];

int tree(int l, int r, int pl) {
    if(l >= r) {
        if(num[l] % 2 == 0 && pl == 0)
            return 1;
        else return 0;
    }

    if(m[l][r] != -1)
        return m[l][r];

    if(pl % 2 == 0) {
        return m[l][r] = max(
            (num[l] % 2 == 0 ? 1 : 0)
                + tree(l + 1, r, pl + 1 % 2),
            (num[r] % 2 == 0 ? 1 : 0)
                + tree(l, r - 1, pl + 1 % 2)
        );
    } else return m[l][r] = min(
        tree(l + 1, r, pl + 1 % 2),
        tree(l, r - 1, pl + 1 % 2)
    );
}

int main() {
    int n;

    cin >> n;
    do {
        memset(m, -1, sizeof(m));

        for(int i = 0; i < 2 * n; i++) {
            int a;
            cin >> a;
            num.push_back(a);
        }

        int r = tree(0, (2 * n) - 1, 0);
        cout << r << '\n';

        num.clear();
        cin >> n;
    } while(n != 0);

    return 0;
}
