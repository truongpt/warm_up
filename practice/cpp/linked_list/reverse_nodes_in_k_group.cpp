/*
- Problem: https://leetcode.com/problems/reverse-nodes-in-k-group
- Need consider solution for memory O(1).
*/

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {};
};

ListNode* reverseKGroup(ListNode* head, int k) {
    std::vector<ListNode*> arr = {};
        
    while (head != nullptr) {
        arr.push_back(head);
        head = head->next;
    }
        
    for (int i = 0; i < arr.size(); i += k) {
        if (i + k-1 < arr.size()) {
            // swap.
            int l = i, r = i+k-1;
            while (l < r) {
                auto temp = arr[r];
                arr[r] = arr[l];
                arr[l] = temp;
                l++, r--;
            }
        }
    }
        
    head = arr[0];
    for (int i = 0; i < arr.size(); i++) {
        if (i != arr.size()-1) {
            arr[i]->next = arr[i+1];
        } else {
            arr[i]->next = nullptr;
        }
    }
    return head;
}

int main(void) {

}
