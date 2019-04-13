#include <bits/stdc++.h>

using namespace std;

long long int fib(long long int n) {
    vector <long long int> f(n + 1, 0);

    f[1] = 2; f[2] = 3;
    for(long long int i = 3; i < n + 1; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}

int main() {
    long long int n;

    while(cin >> n) {
        if(n == 1) {
            cout << "1/1\n";
            continue;
        }

        long long int f = fib(n);
        long long int p = 1LL << n;
        long long int gdc = __gcd(f, p);

        long long int n = f / gdc;
        long long int d = p / gdc;

        cout << n << "/" << d << "\n";
    }

    return 0;
}
