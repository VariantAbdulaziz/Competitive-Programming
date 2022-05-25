// source: https://leetcode.com/problems/swap-nodes-in-pairs/

// strategy: recursion | bottom up approach
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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return NULL;
        if(head->next){
            ListNode* temp;
            temp = head;
            head = head->next;
            temp->next = swapPairs(head->next);
            head->next = temp;
        }
        return head;
    }
};