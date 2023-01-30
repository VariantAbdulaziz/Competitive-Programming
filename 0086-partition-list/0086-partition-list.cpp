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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy_l = new ListNode(0);
        ListNode* dummy_r = new ListNode(0);
        ListNode *left = dummy_l;
        ListNode *right = dummy_r;
        while(head){
            if(head->val >= x){
                right->next = head;
                right = right->next;
            } else {
                left->next = head;
                left = left->next;
            }
            head = head->next;
        }
        left->next = dummy_r->next;
        right->next = nullptr;
        return dummy_l->next;
    }
};