#include <bits/stdc++.h>

using namespace std;

void draw(string line) {
    int times = 0;
    
    for(int i = 0; i < line.size(); i++)  {
        if(isdigit(line[i])) {
            times += (line[i] - '0');
        } else if(line[i] == 'b') {
            while(times > 0) {
                cout << ' ';
                times -= 1;    
            }     
        } else if(line[i] == '!') {
            cout << '\n';
        } else {
            while(times > 0) {
                cout << line[i];
                times -= 1;
            }
        }
    }

    cout << "\n";
}

int main() {
    string line;
    
    while(getline(cin, line)) {
        if(line.size() == 0)
            cout << "\n";
        else
            draw(line);
    }
}
