#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > boardH;
vector <vector <int> > boardV;

int eq(vector <int> v) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == 0)
            continue;
        else return 0;
    }
    return 1;
}

int square(int i, int j, int k) {
    for(int a = 0; a < k; a++) {
        if(boardH[i][j + a] == 0 ||
           boardH[i + k][j + a] == 0 ||
           boardV[i + a][j] == 0 ||
           boardV[i + a][j + k] == 0)
            return 0;
    }
    return 1;
}

int main() {
    int n, m, y = 1;

    cin >> n;
    do {
        cin >> m;

        cout << "Problem #" << y << "\n\n";

        for(int i = 0; i < n; i++) {
            vector <int> v(n, 0);

            boardH.push_back(v);
            boardV.push_back(v);
        }

        for(int i = 0; i < m; i++) {
            char t;
            int x, y;
            cin >> t >> x >> y;

            x -= 1; y -= 1;

            if(t == 'H') 
                boardH[x][y] = 1;
            else
                boardV[y][x] = 1;
        }

        vector <int> counter(n, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int b = min(n - i - 1, n - j - 1);

                for(int k = 1; k <= b; k++) {
                    counter[k - 1] += square(i, j, k);
                }
                
            }
        }

        if(eq(counter)) {
            cout << "No completed squares can be found.\n";
        } else {
            for(int i = 0; i < counter.size(); i++) {
                if(counter[i] > 0)
                    cout << counter[i] 
                        << " square (s) of size "
                        << i + 1 << '\n';
            }
        }

        if(cin >> n) {
            cout << "\n**********************************\n\n";
            y += 1;
        } else break;

        boardH.clear();
        boardV.clear();
    }while(1);
}
