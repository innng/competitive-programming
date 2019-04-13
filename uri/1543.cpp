#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int board[n][m] {};

    do {

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> board[i][j];

        int k;
        cin >> k;



        cin >> n >> m;
    } while(n + m > 0);

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++)
    //         cout << board[i][j] << ' ';
    //     cout << '\n';
    // }

    return 0;
}
