#include <bits/stdc++.h>

using namespace std;

struct People {
    string name;
    int give, receive;
};

int main() {
    int n;

    cin >> n;
    do {
        vector <struct People> people(n);
        map <string, int> rel;

        for(int i = 0; i < n; i++) {
            struct People p;
            cin >> p.name;

            p.give = p.receive = 0;
            people[i] = p;
            rel[p.name] = i;
        }

        for(int i = 0; i < n; i++) {
            string p;
            int id, friends, giving;
            
            cin >> p;
            id = rel[p];            
            cin >> giving >> friends;
            
            if(friends != 0)
                people[id].give = giving - (giving % friends);
            else
                people[id].give = 0;
            
            for(int j = 0; j < friends; j++) {
                int id2;
                cin >> p;
                id2 = rel[p];
                
                people[id2].receive += 
                    (int) people[id].give / friends;
            }
        }

        for(int i = 0; i < n; i++) {
            cout << people[i].name << ' '
                << people[i].receive - people[i].give
                << '\n';
        }      

        if(cin >> n)
            cout << '\n';
        else
            break;

    }while(1);

    return 0;
}
