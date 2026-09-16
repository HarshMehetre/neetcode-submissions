/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*,int> mp;
        ListNode* curr = head;
        if (head==nullptr) return false;
        int i =0;
        while(curr->next != nullptr){
            if(mp.find(curr)!=mp.end()) return true;
            mp[curr] = i++;
            curr = curr->next;
        }
        return false;
        
    }
};
