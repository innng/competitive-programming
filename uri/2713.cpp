#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, v;

    while(cin >> n >> k >> v) {
        double t = 0.0;

        vector <pair <double, pair <double, double > > > diff(n);
        // first é diff
        // second.first é com mana
        // second.second é sem mana

        for(int i = 0; i < n; i++) {
            long hp, d;
            cin >> hp >> d;

            diff[i].second.first =
                (double) hp / (v + d);
            diff[i].second.second =
                (double) hp / v;

            diff[i].first = (double)
                diff[i].second.second
                - diff[i].second.first;
        }

        sort(diff.rbegin(), diff.rend());

        for(int i = 0; i < n; i++) {
            if(k > 0) {
                t += diff[i].second.first;
                k -= 1;
            } else
                t += diff[i].second.second;
        }


        printf("%.4f\n", t);
    }

    return 0;
}
