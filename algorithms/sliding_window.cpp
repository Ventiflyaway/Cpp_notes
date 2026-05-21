#include <bits/stdc++.h>
using namespace std;

int longest_at_most_k_distinct(const string& s, int k) {
    unordered_map<char, int> cnt;
    int l = 0, ans = 0;
    for (int r = 0; r < (int)s.size(); ++r) {
        cnt[s[r]]++;
        while ((int)cnt.size() > k) {
            if (--cnt[s[l]] == 0) cnt.erase(s[l]);
            ++l;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}
