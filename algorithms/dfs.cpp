#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<vector<int>>& g, int u, vector<int>& vis, vector<int>& order) {
    vis[u] = 1;
    order.push_back(u);
    for (int v : g[u]) {
        if (!vis[v]) dfs(g, v, vis, order);
    }
}
