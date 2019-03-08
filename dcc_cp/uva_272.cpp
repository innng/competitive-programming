#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    int open = 0, p;

    getline(cin, line);
    while(line.size() != 0) {
                        
        while((p = line.find("\"")) != string::npos) {
            if(open % 2 == 0) {
                line.replace(p, 1, "``");
            }
            else
                line.replace(p, 1, "''");

            open += 1;
        } 
        cout << line << '\n';
        
        getline(cin, line);
    }
}
