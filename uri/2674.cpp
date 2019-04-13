#include <bits/stdc++.h>

using namespace std;

int isPrime(int n) {
    if(n == 0 || n == 1)
        return 0;

    for(int i = 2; i < (n / 2) + 1; i++)
        if(n % i == 0)
            return 0;

    return 1;
}

int main() {
    int n;

    while(cin >> n) {
        int p = isPrime(n);

        if(p == 0)
            cout << "Nada\n";
        else {
            string digits = to_string(n);
            int prime = 0;

            for (int i = 0; i < digits.length(); i++) {
                int d = digits[i] - '0';
                p = isPrime(d);

                if(p == 0) {
                    prime = 0;
                    cout << "Primo\n";
                    break;
                } else
                    prime = 1;
            }

            if(prime == 1)
                cout << "Super\n";
        }
    }

    return 0;
}
