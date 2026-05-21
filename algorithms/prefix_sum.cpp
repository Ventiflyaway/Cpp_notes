#include <bits/stdc++.h>
using namespace std;

vector<long long> prefix_sum(const vector<int>& a) {
    vector<long long> ps(a.size() + 1, 0);
    for (int i = 0; i < (int)a.size(); ++i) ps[i + 1] = ps[i] + a[i];
    return ps;
}

long long range_sum(const vector<long long>& ps, int l, int r) {
    return ps[r + 1] - ps[l];
}
