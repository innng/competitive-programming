#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;

    cin >> n;
    do {
        long long  x = 0, y = 0, k, t;

        k = floor(sqrt(n));
        t = n - k*k;

        if(t == 0) {
            if(n % 2 == 0) {
                x = k;
                y = 1;
            } else {
                x = 1;
                y = k;
            }
        } else {
            if(k % 2 == 0) {
                x = k + 1;

                if(t <= k + 1) {
                    y = t;
                } else {
                    x -= t % (k + 1);
                    y = k + 1;
                }      
            } else {
                y = k + 1;

                if(t <= k + 1) {
                    x = t;
                } else {
                    x = k + 1;
                    y -= t % (k + 1);
                }    
            }
        }
            
        cout << x << ' ' << y << '\n';

        cin >> n;
    }while(n != 0);

    return 0;
}
