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
    ListNode* deleteMiddle(ListNode* head) {

        if(head->next==NULL) return NULL;

        ListNode*slow=head;
        ListNode*fast=head;

        while(fast && fast->next){
            slow = slow->next;
            if(fast->next){
                fast = fast->next->next;
            }
        }

        ListNode*prev=head;
        while(prev->next != slow){
            prev = prev->next;
        }

        prev->next = slow->next;
        return head;
    }
};