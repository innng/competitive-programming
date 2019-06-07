#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct Edge
{
    int v, rev;
    ll cap;
    Edge(int v_, ll cap_, int rev_) : v(v_), rev(rev_), cap(cap_) {}
};

struct Dinic
{
    vector<vector<Edge> > g;
    vector<int> level;
    queue<int> q;
    ll flow;
    int n;

    Dinic(int n_) : g(n_), level(n_), n(n_) {}

    void addEdge(int u, int v, ll cap)
    {
        if(u == v) return;
        Edge e(v, cap, int(g[v].size()));
        Edge r(u, 0, int(g[u].size()));
        g[u].push_back(e);
        g[v].push_back(r);
    }

    bool buildLevelGraph(int src, int sink)
    {
        fill(level.begin(), level.end(), -1);
        while(not q.empty()) q.pop();
        level[src] = 0;
        q.push(src);
        while(not q.empty())
        {
            int u = q.front();
            q.pop();
            for(vector<Edge>::iterator e=g[u].begin();e!=g[u].end();e++)
            {
                if(not e->cap or level[e->v] != -1) continue;
                level[e->v] = level[u] + 1;
                if(e->v == sink) return true;
                q.push(e->v);
            }
        }
        return false;
    }

    ll blockingFlow(int u, int sink, ll f)
    {
        if(u == sink or not f) return f;
        ll fu = f;
        for(vector<Edge>::iterator e=g[u].begin();e!=g[u].end();e++)
        {
            if(not e->cap or level[e->v] != level[u] + 1) continue;
            ll mincap = blockingFlow(e->v, sink, min(fu, e->cap));
            if(mincap)
            {
                g[e->v][e->rev].cap += mincap;
                e->cap -= mincap;
                fu -= mincap;
            }
        }
        if(f == fu) level[u] = -1;
        return f - fu;
    }

    ll maxFlow(int src, int sink)
    {
        flow = 0;
        while(buildLevelGraph(src, sink))
            flow+= blockingFlow(src, sink, numeric_limits<ll>::max());
        return flow;
    }
};

int main() {
    int n, m, k, y = 1;

    while(cin >> n >> m >> k) {
        cout << "Instancia " << y++ << '\n';

        int sz = n + m + 10;
        Dinic d = Dinic(sz);

        for(int i = 1; i <= n; i++) {
            int c;
            cin >> c;

            d.addEdge(m + i, n + m + 1, c);
            d.addEdge(n + m + 1, m + i, c);
        }

        for(int i = 0; i < k; i++) {
            int u, v;
            cin >> u >> v;

            d.addEdge(u + m, v, 1);
            d.addEdge(v, u + m, 1);
        }

		for(int i = 1; i <= m; i++) {
            d.addEdge(0, i, 1);
            d.addEdge(i, 0, 1);
		}

        cout << d.maxFlow(0, n + m + 1) << '\n';
    }

    return 0;
}
