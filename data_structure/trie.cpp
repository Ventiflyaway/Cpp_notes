#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    array<int, 26> next;
    bool end;
    TrieNode() : end(false) { next.fill(-1); }
};

struct Trie {
    vector<TrieNode> nodes;
    Trie() { nodes.emplace_back(); }

    void insert(const string& s) {
        int p = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (nodes[p].next[c] == -1) {
                nodes[p].next[c] = (int)nodes.size();
                nodes.emplace_back();
            }
            p = nodes[p].next[c];
        }
        nodes[p].end = true;
    }

    bool search(const string& s) const {
        int p = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (nodes[p].next[c] == -1) return false;
            p = nodes[p].next[c];
        }
        return nodes[p].end;
    }
};
