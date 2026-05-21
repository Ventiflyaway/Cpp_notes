#include <bits/stdc++.h>
using namespace std;

int lowbit(int x) {
    return x & -x;
}

bool is_power_of_two(int x) {
    return x > 0 && (x & (x - 1)) == 0;
}
