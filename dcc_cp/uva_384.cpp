#include <bits/stdc++.h>

#define YES cout << "YES\n"
#define NO cout << "NO\n"

using namespace std;

int slump(char* str, int i) {
    if(str[i] == 'D' || str[i] == 'E') {
        i++;
        if(str[i] == 'F') {
            i++;

            while(str[i] == 'F') {
                i++;
            }

            if(str[i] == 'G') {
                i++;
                return i;
            } else {
                int su = slump(str, i);
                return su;
            }
        } else return -1;
    } else return -1;
}

int slimp(char* str, int i) {
    if(str[i] == 'A') {
        i++;
        if(str[i] == 'H') {
            i++;
            return i;
        } else if(str[i] == 'B') {
            i++;
            int si = slimp(str, i);
            
            if(str[si] == 'C') {
                si++;
                return si;
            } else return -1;
        } else {
            int su = slump(str, i);
            
            if(str[su] == 'C') {
                su++;
                return su;
            } else return -1;
        }
    } else return -1;
}

int main() {
    int n;

    cin >> n;

    cout << "SLURPYS OUTPUT\n";

    for(int i = 0; i < n; i++) {
        char string[60];

        cin >> string;

        int si = slimp(string, 0);

        if(si != -1) {
            int su = slump(string, si);

            if(su != -1 && strlen(string) == su) {
                YES;
            } else NO;
        } else NO;     
    }

    cout << "END OF OUTPUT\n";
    return 0;
}

