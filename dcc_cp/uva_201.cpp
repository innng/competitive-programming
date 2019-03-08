#include <bits/stdc++.h>

#define A 0
#define H 1
#define V 2

using namespace std;

int main() {
    int n, m, y = 1;
    
    while(cin >> n >> m) {
        vector <vector <int> > board(n, vector<int>(n, -1)),
            visited(n, vector<int>(n, -1));

        cout << "Problem #" << y << '\n';

        for(int u = 0; u < m; u++) {
            char type;
            int i, j;
            cin >> type >> i >> j;

            i -= 1;
            j -= 1;

            if(type == 'H') {
                if(board[i][j] == -1)
                    board[i][j] = H;
                else
                    board[i][j] = A;
            } else {
                if(board[j][i] == -1)
                    board[j][i] = V;
                else
                    board[j][i] = A;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int x = 0; x < n; x++) {
                for(int y = 0; y < n; y++) {
                       
                }
            }
        }
        y += 1;

        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) 
        //         cout << board[i][j] << ' ';
        //     cout << '\n';
        // }
    }

    return 0;   
}
