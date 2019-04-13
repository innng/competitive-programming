#include <bits/stdc++.h>

using namespace std;

int fact(int a, int b) {
    int f = 1;
    for(int i = 1; i < min(a, b) + 1; i++)
        f *= i;

    return f;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << fact(a, b) << '\n';
    return 0;
}
