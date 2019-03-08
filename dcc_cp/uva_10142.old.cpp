#include <bits/stdc++.h>

using namespace std;

vector < pair<string, int> > candidate;
vector <vector <int> > ballots;

int allEqual(
    // const vector <pair <string, int> > &candidate,
    const vector <int> &eliminated
) {
    int i;
    for(i = 0; i < candidate.size(); i++)
        if(eliminated[i] == 0) 
            break;
    
    for(int j = i + 1; j < candidate.size(); j++)
        if(eliminated[j] == 0) {
            if(candidate[j].second == candidate[i].second)
                continue;
            else return -1;
        }

    return 1;
}

void calculate(
    int n
    // vector < pair<string, int> > &candidate,
    // vector <vector <int> > &ballots
) {
    float majority = ballots.size() * 0.5;
    vector <int> eliminated(n, 0);
    int end = 0;
    
    do {
        for(int i = 0; i < n; i++)
            if(eliminated[i] == 0)
                candidate[i].second = 0;

        for(int i = 0; i < ballots.size(); i++) {
            int j = 0, id;
            
            do {
                id = ballots[i][j] - 1;
                j++;
            } while(eliminated[id] == 1);

            candidate[id].second += 1;
        }
            
        for(int i = 0; i < candidate.size(); i++) {
            if(candidate[i].second > majority) {
                cout << candidate[i].first << '\n';
                end = 1;
            }
        }

        if(end == 1)
            break;

        // if(allEqual(candidate, eliminated) == 1) {
        if(allEqual(eliminated) == 1) {
            for(int i = 0; i < candidate.size(); i++)
                if(eliminated[i] == 0)
                    cout << candidate[i].first << '\n';
            break;
        }
        
        if(end == 1)
            break;

        int min;
        for(int i = 0; i < candidate.size(); i++)
            if(eliminated[i] == 0) {
                min = candidate[i].second;
                break;
            }

        for(int i = 0; i < candidate.size(); i++) {
            if(eliminated[i] == 0)
                if(candidate[i].second < min)
                    min = candidate[i].second;
        }
        
        for(int i = 0; i < candidate.size(); i++) {
            if(eliminated[i] == 0)
                if(candidate[i].second == min) {
                    candidate[i].second = -1;
                    eliminated[i] = 1;
                }
        }
    }while(1);

    eliminated.clear();
}

int main() {
    int t;
    // vector < pair<string, int> > candidate;
    // vector <vector <int> > ballots;

    cin >> t;

    for(int y = 0; y < t; y++) {
        int n;
        cin >> n;
        cin.ignore(1, '\n');

        // fflush(stdin);
        // scanf("%d", &n);

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
            int i = 0;
    
            while(ssin.good() && i < n){
                ssin >> v[i];
                i++;
            }
            ballots.push_back(v);
        }
        
        calculate(n); 
        // , candidate, ballots);

        if(y != t - 1)
            cout << '\n';
        
        candidate.clear();
        ballots.clear();
    }
}
