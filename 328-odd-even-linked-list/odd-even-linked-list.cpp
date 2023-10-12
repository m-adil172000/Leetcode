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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        if(head->next->next==NULL) return head;

        ListNode*prev1=head;
        ListNode*prev2=head->next;
        ListNode*curr1=head;
        ListNode*curr2=head->next;
        ListNode*s2=head->next;
        ListNode*s1=head;

        while(curr2!=NULL && curr2->next!=NULL){
            curr1= curr1->next->next;
            curr2= curr2->next->next;
            prev1->next = curr1;
            prev2->next = curr2;

            prev1 = curr1;
            prev2 = curr2;
        }

        curr1->next=s2;

        return s1;
    }
};