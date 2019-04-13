#include <bits/stdc++.h>

#define INF 1e6

using namespace std;

vector <vector <int> > matrix;

void calculate(int c) {
    for (int i = 0; i < c; i++) { 
        for(int j = 0; j < c; j++) { 
            if(i != j && matrix[i][j] == 0) 
                matrix[i][j] = INF;
        }
    }

    for(int k = 0; k < c; k++) { 
        for (int i = 0; i < c; i++) { 
            for(int j = 0; j < c; j++) { 
                matrix[i][j] = min(max(matrix[i][k], matrix[k][j]), matrix[i][j]);
            } 
        } 
    } 
}

void find(int s, int t) {
    if(matrix[s][t] == INF)
        cout << "no path\n";
    else
        cout << matrix[s][t] << '\n';
}

int main() {
    int c, s, q, y = 1;

    cin >> c >> s >> q;
    do {
        cout << "Case #" << y << '\n';

        for(int i = 0; i < c + 10; i++) {
            vector <int> v(c + 10, 0);

            matrix.push_back(v);
        }
        
        for(int i = 0; i < s; i++) {
            int a, b, c;
            cin >> a >> b >> c;

            a -= 1;
            b -= 1;

            matrix[a][b] = c;
            matrix[b][a] = c;
        }

        calculate(c);

        for(int i = 0; i < q; i++) {
            int a, b;
            cin >> a >> b;

            a -= 1;
            b -= 1;

            find(a, b);            
        }
        
        cin >> c >> s >> q;

        if(c + s + q > 0)
            cout << '\n';

        matrix.clear();

        y += 1;
    }while(c + s + q > 0);
}
