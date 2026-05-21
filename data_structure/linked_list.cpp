#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode* build_list(const vector<int>& nums) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int x : nums) {
        tail->next = new ListNode(x);
        tail = tail->next;
    }
    return dummy.next;
}

ListNode* reverse_list(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* next_node = head->next;
        head->next = prev;
        prev = head;
        head = next_node;
    }
    return prev;
}
