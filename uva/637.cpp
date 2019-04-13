#include <bits/stdc++.h>

#define BLANK "Blank"
#define COLON ", "

using namespace std;

void print(int n) {
    cout << "Printing order for " << n << " pages:\n";

    if(n == 1) {
        cout << "Sheet 1, front: Blank, 1\n";
        return;
    }

    int sub = 4 - (n % 4), m;
    
    if(sub < 4)
        m = n + sub;
    else
        m = n;

    int pg = 1, i = m, j = 1, k = 0;

    while(i > j) {
        cout << "Sheet " << pg << COLON;

        if(k % 2 == 0) {
            cout << "front: ";

            if(i > n)
                cout << BLANK << COLON << j << '\n';
            else
                cout << i << COLON << j << '\n';
        } else {
            cout << "back : ";

            if(i > n)
                cout << j << COLON << BLANK << '\n';
            else
                cout << j << COLON << i << '\n';

            pg += 1;
        }

        k += 1;
        i -= 1;
        j += 1;
    }    
}

int main() {
    int n;

    cin >> n;
    do {
        print(n);

        cin >> n;
    } while(n != 0);

    return 0;
}
