#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int y = 0; y < t; y++) {
        int n, k, r;

        cin >> n;

        vector <int> p(n);
        vector <int> w(n);

        for(int i = 0; i < n; i++) {
            cin >> p[i] >> w[i];
        }

        cin >> k >> r;

        int m[n + 1][k + 1] {};

        for(int i = 0; i < n; i++) { 
            for(int j = 1; j <= k; j++) { 
                if(w[i] <= j) 
                    m[i + 1][j] = max(p[i] + m[i][j - w[i]],  m[i][j]); 
                else
                    m[i + 1][j] = m[i][j]; 
            } 
        }

        if(m[n][k] >= r)
            cout << "Missao completada com sucesso\n";
        else
            cout << "Falha na missao\n";
        
        p.clear();
        w.clear();
    }

    return 0;
}

