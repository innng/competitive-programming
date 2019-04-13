#include <bits/stdc++.h>

using namespace std;

set <string> jewels;

int main() {
    string line;

    while(getline(cin, line)) {
        jewels.insert(line);
    }

    cout << jewels.size() << '\n';
    return 0;
}
