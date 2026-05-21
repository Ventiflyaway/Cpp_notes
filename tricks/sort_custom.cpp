#include <bits/stdc++.h>
using namespace std;

struct Item {
    int id;
    int score;
};

void demo_sort() {
    vector<Item> a = {{1, 90}, {2, 70}, {3, 90}};
    sort(a.begin(), a.end(), [](const Item& x, const Item& y) {
        if (x.score != y.score) return x.score > y.score;
        return x.id < y.id;
    });
}
