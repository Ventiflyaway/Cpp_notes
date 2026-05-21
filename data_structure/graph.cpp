#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> build_graph(int n, const vector<pair<int, int>>& edges, bool directed = false) {
    vector<vector<int>> g(n);
    for (auto [u, v] : edges) {
        g[u].push_back(v);
        if (!directed) g[v].push_back(u);
    }
    return g;
}

vector<int> bfs(const vector<vector<int>>& g, int start) {
    vector<int> order;
    vector<int> vis(g.size(), 0);
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    return order;
}
