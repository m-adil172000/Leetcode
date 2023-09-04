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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nxt = curr->next;


        while(nxt != NULL){
            if(nxt==head){
                return true;
            }
            else{
                curr->next=prev;
                prev=curr;
                curr=nxt;
                nxt = nxt->next;
            }
        }

        return false;
    }
};