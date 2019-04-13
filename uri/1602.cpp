#include <bits/stdc++.h>

#define MAX 10e6

using namespace std;

int main() {
    int n;

    vector <int> primes(MAX, 1);

    for(int i = 2; i * i < MAX; i++)
        if(primes[i] == 1)
            for(int j = i * i; j < MAX; j += i)
                primes[j] = 0;

    while(cin >> n) {
        int c = 0;

        for(int i = 2; i < n + 1; i++) {
            if(primes[i] == 1)
                c++;
            else {
                int j = sqrt(i);
                if(j - floor(j) == 0)
                    c++;
            }
        }

        cout << c << '\n';
    }

    return 0;
}
