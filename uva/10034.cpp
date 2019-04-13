#include <bits/stdc++.h>

using namespace std;

vector <int> parent;
vector <int> ranking;
vector <pair <double, double> > edges;
vector <pair <double, pair <int, int> > > weights;

double euclidian_distance(
    pair <double, double> a, pair <double, double> b) {
    
    return sqrt((b.first - a.first)*(b.first - a.first) + 
        (b.second - a.second)*(b.second - a.second));
}

int _find(int a) {
	if (parent[a] == a)
		return a;

	int t = a;

	while (parent[t] != t)
		t = parent[t];

	while (parent[a] != a) {
		int c = parent [a];
		parent[a] = t;
		a = c;
	}

	return t;
}

void _union(int a, int b) {
	a = _find(a);
	b = _find(b);

	if (ranking[a] > ranking[b]) {
		parent[b] = a;
	} else if(ranking[a] < ranking[b]) {
		parent[a] = b;
	}
	else {
		parent[b] = a;
		ranking[a] += 1;
	}
}

int main() {
    int t;
    cin >> t;

    for(int y = 0; y < t; y++) {
        cin.ignore(1, '\n');
        int n; 
        cin >> n;

        // if(n == '\n')
        //     cin >> n;

        for(int i = 0; i < n; i++) {
            pair <double, double> p;
            cin >> p.first >> p.second;

            edges.push_back(p);            
        }
        
        for(int i = 0; i < edges.size(); i++) {
            for(int j = i + 1; j < edges.size(); j++) {
                pair <double, pair <int, int> > p;
                if(i != j) {
                    p.first = euclidian_distance(edges[i], edges[j]);
                    p.second.first = i;
                    p.second.second = j;

                    weights.push_back(p);
                }
            }
        }

        for(int i = 0; i < edges.size(); i++) {
            parent.push_back(i);
            ranking.push_back(0);
        }

        sort(weights.begin(), weights.end());

        // int m = n, i = 0;
        double result = 0.0;

        // while(m > 1) {
        //     int a = _find(weights[i].second.first);
        //     int b = _find(weights[i].second.second);

        //     if(a != b) {
        //         result += weights[i].first;
                
        //         _union(a, b);
        //         m -= 1;
        //     }

        //     i+= 1;
        // }

        for(int i = 0; i < weights.size(); i++) {
            int a = _find(weights[i].second.first);
            int b = _find(weights[i].second.second);

            if(a != b) {
                result += weights[i].first;
                
                _union(a, b);
                // m -= 1;
            }
        }
        

        printf("%.2f\n", result);
        // cout << result << '\n';

        // for(int i = 0; i < weights.size(); i++) {
        //     cout << weights[i].first << ' '
        //         << weights[i].second.first << ' '
        //         << weights[i].second.second << '\n';
        // }  

        if(y != t - 1)
            cout << '\n';

        parent.clear();
        ranking.clear();
        edges.clear();
        weights.clear();
    }
    return 0;
}
