#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    while(cin >> n) {
        int yes = 0;
        int sqr = sqrt(n);

        for(int i = 0; i <= sqr; i++) {
            for(int j = i; j <= sqr; j++) {
                int result = i*i + j*j;

                if(result == n) {
                    yes = 1;
                }                 
            }

            if(yes)
                break;            
        }

        if(yes || n == 1 || n == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
        
    }
}
