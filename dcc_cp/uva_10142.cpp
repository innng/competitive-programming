#include <bits/stdc++.h>

using namespace std;

vector <pair <string, int> > candidate;
vector <pair <vector <int>, int> > ballot;
int n;

int eq() {
    int i;
    for(i = 0; i < candidate.size(); i++) {
        if(candidate[i].second != -1)
            break;
    }

    for(int j = i + 1; j < candidate.size(); j++) {
        if(candidate[j].second != -1) {
            if(candidate[j].second == candidate[i].second)
                continue;
            else return 0;
        }
    }
    
    return 1;
}

void calculate() {
    float majority = ballot.size() * 0.5;
        
    do {
        // reset votes
        for(int i = 0; i < candidate.size(); i++) {
            if(candidate[i].second != -1)
                candidate[i].second = 0;
        }

        // calculate votes
        for(int i = 0; i < ballot.size(); i++) {
            int ptr = ballot[i].second;
            int id = ballot[i].first[ptr] - 1;

            if(candidate[id].second != -1) 
                candidate[id].second += 1;
        }

        // find the winner(s)
        for(int i = 0; i < candidate.size(); i++) {
            if(candidate[i].second > majority) {
                cout << candidate[i].first << '\n';
                return;
            }
        }

        if(eq() == 1) {
            for(int i = 0; i < candidate.size(); i++) {
                if(candidate[i].second != -1) 
                    cout << candidate[i].first << '\n';
            }

            return;
        }

        // find the least voted
        int min, i;
        for(i = 0; i < candidate.size(); i++) {
            if(candidate[i].second != -1) {
                min = candidate[i].second;
                break;
            }
        }

        for(int j = i + 1; j < candidate.size(); j++) {
            if(candidate[j].second != -1) {
                if(candidate[j].second < min)
                    min = candidate[j].second;
            }
        }

        vector <int> excluded;
        
        // exclude candidates
        for(i = 0; i < candidate.size(); i++) {
            if(candidate[i].second != -1 && 
                candidate[i].second == min) {
                candidate[i].second = -1;
                excluded.push_back(i);
            }
        }

        // update votes' matrix
        for(int i = 0; i < ballot.size(); i++) {
            int ptr = ballot[i].second, id;

            do {
                id = ballot[i].first[ptr] - 1;

                if(candidate[id].second == -1)
                    ptr += 1;
                else break;
            } while(1);

            ballot[i].second = ptr;
        }

    } while(1);
}

int main() {
    int t;
    cin >> t;

    for(int y = 0; y < t; y++) {
        cin >> n;
        cin.ignore(1, '\n');
        
        for(int i = 0; i < n; i++) {
            pair <string, int> p;
            getline(cin, p.first);
            p.second = 0;

            candidate.push_back(p);
        }
        
        string line;
        while(getline(cin, line)) {
            if(line.size() == 0)
                break;

            stringstream ssin(line);
            vector <int> v(n);
            pair <vector <int>, int> p;
            int i = 0;

            while(ssin.good() && i < n) {
                ssin >> v[i];
                i += 1;
            }

            p.first = v;
            p.second = 0;
            ballot.push_back(p);
        }
      
        calculate();

        if(y != t - 1)
            cout << '\n';

        candidate.clear();
        ballot.clear();
    }
    
    return 0;
}
