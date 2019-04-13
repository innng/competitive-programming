#include <bits/stdc++.h>

#define A 65
#define LETTERS 26
#define INF 1e6
#define NO cout << "You will never meet.\n"

using namespace std;

vector <vector <int> > matrixY;
vector <vector <int> > matrixM;

void calculate() {   
    for (int i = 0; i < LETTERS; i++) { 
        for(int j = 0; j < LETTERS; j++) { 
            if(i == j)
                matrixY[i][j] = matrixM[i][j] = 0;
        }
    }

    for(int k = 0; k < LETTERS; k++) { 
        for (int i = 0; i < LETTERS; i++) { 
            for(int j = 0; j < LETTERS; j++) { 
                matrixY[i][j] = min(matrixY[i][k] + matrixY[k][j], matrixY[i][j]);
                matrixM[i][j] = min(matrixM[i][k] + matrixM[k][j], matrixM[i][j]);
            } 
        } 
    } 
}

void find(int y, int m) {
    int cost = matrixY[y][0] + matrixM[m][0];

    for(int i = 1; i < LETTERS; i++) {
        if(cost > matrixY[y][i] + matrixM[m][i]) 
            cost = matrixY[y][i] + matrixM[m][i];
    }

    if(cost == INF) {
        NO;
        return;
    }

    cout << cost;
    for(int i = 0; i < LETTERS; i++) {
        if(matrixY[y][i] + matrixM[m][i] == cost) {
            char c = i + A;
            cout << ' ' << c;
        }
    }
    cout << '\n';
}

int main() {
    int n;
    
    cin >> n;
    do {
        for(int i = 0; i < LETTERS; i++) {
            vector <int> v(LETTERS, INF);

            matrixY.push_back(v);
            matrixM.push_back(v);
        }

        for(int i = 0; i < n; i++) {
            vector <int> v;
            char a, b, c, d;
            int w, x, y;
            cin >> a >> b >> c >> d >> w;
            
            x = c - A;
            y = d - A;

            if(a == 'Y') {
                matrixY[x][y] = w;
                if(b == 'B') {
                    matrixY[y][x] = w;
                }
            } else if(a == 'M') {
                matrixM[x][y] = w;
                if(b == 'B') {
                    matrixM[y][x] = w;
                }
            }            
        }

        calculate();

        char a, b;
        int x, y;

        cin >> a >> b;
        x = a - A;
        y = b - A;

        find(x, y);
        
        cin >> n;

        matrixY.clear();
        matrixM.clear();
    }while(n != 0);
    
    return 0;
}
