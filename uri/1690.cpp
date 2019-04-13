#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int y = 0; y < t; y++) {
        int n;
        cin >> n;

        vector <int> v(n, 0);

        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int sz = n*n;        
        vector <int> sum(sz, 0);

        if(sz == 1) {
            sum[0] = v[0];
        } else {
            for(int i = 1; i <= sz; i++) {
                int a = 0; 
                for(int j = 0; j < n; j++) {
                    if(i & (1 << j))
                        a += v[j];
                }
                sum[i] = a;
            }
        }

        sort(sum.begin(), sum.end());

        for(int i = 0; i < sum[sz - 1]; i++) {
                        
        }
        
                
        v.clear();
        sum.clear();
    }
    

    return 0;
}
