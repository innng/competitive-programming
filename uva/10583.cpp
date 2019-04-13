#include <bits/stdc++.h>

using namespace std;

vector <int> parent;
vector <int> ranking;

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
    int n, m, k = 1;

    cin >> n >> m;
    do {
        int out = n;

        cout << "Case " << k << ": ";

        for(int i = 0; i < n; i++) {
            parent.push_back(i);
            ranking.push_back(0);
        }

        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;

            a -= 1;
            b -= 1;
            
            a = _find(a);
            b = _find(b);

            if(a != b) {
                _union(a, b);
                out -= 1;
            }
            
        }

        cout << out << '\n';

        k += 1;

        parent.clear();
        ranking.clear();

        cin >> n >> m;
    } while(n + m > 0);
}
