#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(1, '\n');
    
    for(int i = 0; i < n; i++) {
        int count = 0, open = 0;
        string line;
        getline(cin, line);
        
        for(int j = 0; j < line.size(); j++) {
            if(line[j] == '<') 
                open += 1;
            else if(line[j] == '>' && open > 0) {
                open -= 1;
                count += 1;
            }
        }
        
        cout << count << '\n';
    }
    
    return 0;
}
