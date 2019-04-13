#include <bits/stdc++.h>

using namespace std;

void convert(string line) {
    int i = 0;

    while(i < line.size()) {
        if(isalpha(line[i])) {
            if('a' == line[i] || 'A' == line[i] ||
               'e' == line[i] || 'E' == line[i] || 
               'i' == line[i] || 'I' == line[i] || 
               'o' == line[i] || 'O' == line[i] || 
               'u' == line[i] || 'U' == line[i] ) {
                while(isalpha(line[i])) {
                    cout << line[i];
                    i += 1;
                }
     
            } else {
                char c = line[i];
                i += 1;

                while(isalpha(line[i])) {
                    cout << line[i];
                    i += 1;
                }

                cout << c;
            }

            cout << "ay";
        } else {
            cout << line[i];
            i += 1;
        }
    }
    cout << '\n';
}

int main() {
    string line;

    while(getline(cin, line)) {
        convert(line);
    }

    return 0;
}
