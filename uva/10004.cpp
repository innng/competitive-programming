#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > matrix;
vector <int> colors;

int bicolored() {
    vector <int> next;

    next.push_back(0);
    colors[0] = 0;

    while(!next.empty()) {
        int v = next[0];

        next.erase(next.begin());

        for(int i = 0; i < matrix[v].size(); i++) {
            int n = matrix[v][i];

            if(colors[n] == -1) {
                colors[n] = (colors[v] + 1) % 2;
                next.push_back(n);
            } else if(colors[n] == colors[v]) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int n, e;

    cin >> n;
    do {
        cin >> e;

        for(int i = 0; i < n; i++) {
            vector <int> v;
            matrix.push_back(v);
            colors.push_back(-1);
        }

        for(int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;

            matrix[a].push_back(b);
            matrix[b].push_back(a);
        }

        if(bicolored())
            cout << "BICOLORABLE.\n";
        else 
            cout << "NOT BICOLORABLE.\n";
        
        cin >> n;
        matrix.clear();
        colors.clear();
    }while(n != 0);
    return 0;
}
