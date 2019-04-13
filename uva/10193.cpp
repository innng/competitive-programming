#include <bits/stdc++.h>

#define B 30

using namespace std;

void test(long s1, long s2, int x){
    if(__gcd(s1,s2) != 1)
        cout << "Pair #" << x << ": All you need is love!" << endl;
    else
        cout << "Pair #" << x << ": Love is not all you need!" << endl;
}

int main(int argc, char const *argv[]){
    uint n, x = 0;
    string s1, s2;

    cin >> n;
    while(n--){
        x++;
        cin >> s1 >> s2;
        test(bitset<B>(string(s1)).to_ulong(),bitset<B>(string(s2)).to_ulong(), x);
    }

    return 0;
}
