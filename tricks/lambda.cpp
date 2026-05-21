#include <bits/stdc++.h>
using namespace std;

void demo_lambda() {
    vector<int> a = {1, 2, 3};
    int sum = 0;
    for_each(a.begin(), a.end(), [&](int x) {
        sum += x;
    });
}
