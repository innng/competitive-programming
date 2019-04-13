#include <bits/stdc++.h>

using namespace std;

int factor(int k) {
    if(k == 1)
        return 1;
    return k * factor(k - 1);
}

int main() {
    int n;
    cin >> n;

    int count = 0, rmd = n;

    while(rmd > 0) {
        int i;
        for(i = 2; i <= rmd; i++) {
            int f = factor(i);
            if(f > rmd)
                break; 
        }

        rmd -= factor(i - 1);
        count += 1;
    }

    cout << count << '\n';
      
    return 0;
}
