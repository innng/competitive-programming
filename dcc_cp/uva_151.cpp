#include <bits/stdc++.h>

using namespace std;

int execute(int n, int m) {
    int v = n, i = 0;
    int visited[n] = {0};

    while(v != 1) {
        visited[i] = 1;
        v -= 1;

        int j = i, k = 0;
        while(k < m) {
            if(visited[(j + 1) % n] == 0) {
                i = (j + 1) % n;
                k += 1;
            }
            j += 1;
        }
    }

    return i;
}

int main() {
    int n, m;

    cin >> n;
    do {
        for(m = 0; ; m++) {
            int last = execute(n, m);

            if(last + 1 == 13) break;
            else continue;
        }

        cout << m << '\n';
        
        cin >> n;
    }while(n != 0);

    return 0;
}
