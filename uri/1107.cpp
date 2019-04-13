#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, c;

    cin >> a >> c;

    do {
        vector <int> v(c, 0);

        for(int i = 0; i < c; i++) {
            cin >> v[i];
        }
        
        cin >> a >> c;
    } while(a + c > 0);
    return 0;
}
