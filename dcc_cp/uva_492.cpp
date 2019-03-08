#include <bits/stdc++.h>

using namespace std;

void convert(string line) {
    istringstream iss(line);
    vector<string> words {
        istream_iterator <string> {iss},
        istream_iterator <string> {}
    };

    for(int i = 0; i < words.size(); i++) {
        if(
            words[i][0] == 'a' || words[i][0] == 'A' || 
            words[i][0] == 'e' || words[i][0] == 'E' || 
            words[i][0] == 'i' || words[i][0] == 'I' || 
            words[i][0] == 'o' || words[i][0] == 'O' || 
            words[i][0] == 'u' || words[i][0] == 'U'
        ) {
            cout << words[i] << "ay";
        } else {
            cout << words[i];
        }

        cout << ' ';
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
