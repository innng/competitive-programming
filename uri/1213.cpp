#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n;

    while(cin >> n) {
        long long int d = 1;
        for(long long int j = 1; ; j = (j * 10 + 1) % n)
            if(j % n == 0) {
                cout << d << '\n';
                break;
            } else d += 1;
    }

    return 0;
}
