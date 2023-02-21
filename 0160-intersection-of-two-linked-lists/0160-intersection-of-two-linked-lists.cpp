/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int len(ListNode *head) {
        int n = 0;
        while(head) {
            head = head->next;
            n++;
        }
        return n;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int an = len(headA);
        int bn = len(headB);
        int n = abs(an - bn);
        auto tail_long = an > bn? headA: headB;
        auto tail_short = an <= bn? headA: headB;
        
        while(n--) {
            tail_long = tail_long->next;
        }
        while(tail_long != tail_short) {
            tail_long = tail_long->next;
            tail_short = tail_short->next;
        }
        return tail_long;
    }
};