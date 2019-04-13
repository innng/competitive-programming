#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n, k;

    cin >> n >> k;
    do {
        vector <long long int> num(n, 0);
        long long int aux[k][n] {};

        for(long long int i = 0; i < n; i++) {
            cin >> num[i];
            aux[0][i] = 1;
        }

        for(long long int i = 1; i < k; i++)
            for(long long int j = i; j < n; j++)
                for(long long int l = i - 1; l < j; l++)
                    if(num[l] < num[j])
                        aux[i][j] += aux[i - 1][l];

        long long int sum = 0;
        for(long long int i = 0; i < n; i++)
            sum += aux[k - 1][i];

        cout << sum << '\n';

        cin >> n >> k;
    } while(n + k > 0);

    return 0;
}
