#include <bits/stdc++.h>

using namespace std;

map <string, string> table;

int main() {
    int n, m;
    cin >> n;
    cin.ignore(1, '\n');
    
    for(int i = 0; i < 2 * n; i+= 2) {
        string a, b;
        
        getline(cin, a);
        getline(cin, b);

        table[a] = b;
    }
    
    cin >> m;
    cin.ignore(1, '\n');
    
    for(int i = 0; i < 2 * m; i+= 2) {
        string a, b;
        
        getline(cin, a);
        getline(cin, b);

        cout << a << '\n';
        cout << table[b] << "\n\n";
    }
    
    return 0;
}
