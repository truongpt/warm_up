/*
  - Problem: https://leetcode.com/problems/copy-list-with-random-pointer/
  - Solution:
  - Straightforward create clone tree with correct value and next pointer
  - Random pointer is mapped by hashtable with clone and original node.
  - Time and space complexity.
  - TC: O(n)
  - SC: O(n)
*/

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(): val(0), next(nullptr), random(nullptr) {};
    Node(int v): val(v), next(nullptr), random(nullptr) {};
};

Node* copyRandomList(Node* head) {
    Node* res = new Node(0);
        
    unordered_map<Node*, Node*> m;
    m[nullptr] = nullptr;
        
    Node* clone = res;
    Node* org = head;
    while (head) {
        Node* c = new Node(head->val);
        m[head] = c;
        clone->next = c;
        clone = clone->next;
        head = head->next;
    }
        
    clone = res->next;
    head = org;
    while (head) {
        clone->random = m[head->random];
        head = head->next;
        clone = clone->next;
    }
        
    return res->next;
}

int main(void)
{

}
