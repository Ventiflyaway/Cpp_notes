#include <bits/stdc++.h>
using namespace std;

int interval_scheduling(vector<pair<int, int>> intervals) {
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
    int cnt = 0;
    int last_end = INT_MIN;
    for (auto [l, r] : intervals) {
        if (l >= last_end) {
            ++cnt;
            last_end = r;
        }
    }
    return cnt;
}
