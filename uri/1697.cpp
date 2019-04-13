#include <bits/stdc++.h>

#define MAX 10e6 + 10

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int y = 0; y < t; y++) {
        long long int n;
        cin >> n;

        vector <long long int> num(MAX, 0);

        for(long long int i = 0; i < n; i++) {
            long long int m;
            cin >> m;

            num[m] = 1;
        }

        if(num[1] == 0)
            cout << "0\n";
        else {
            long long int i;
            for(i = 2; i < MAX; i++)
                if(num[i] == 0) {
                    break;
                } else {
                    for(long long int j = 2 * i; j < MAX; j += i)
                        num[j] = 1;
                }

            cout << i - 1 << '\n';
        }
    }

    return 0;
}
